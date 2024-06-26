#include "Planar/Engine/Scene/SceneAsset.hpp"
#include "Planar/Engine/Asset/AssetFunction.hpp"
#include "Planar/Engine/Core/Constants/Version.hpp"
#include "Planar/Engine/Core/GUID/GUID.hpp"
#include "Planar/Engine/Core/Utils/Checks/Assert.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

#include <memory>

namespace Planar::Engine::Scene
{
    SceneAsset::SceneAsset()
    {

    }

    void SceneAsset::create(std::string scene_asset,
        const std::filesystem::path& path,
        const std::string& scene_name)
    {
        name = scene_name;
        scene_asset = Engine::Asset::preprocess_asset(scene_asset,
            {
                { "<VERSION>", Core::Constants::VERSION },

                { "<GUID>", Core::GUID::generate_guid(
                    Core::GUID::Representation::DEFAULT_COMPACT) },
            });

        Core::FileSystem::create_file(path / (scene_name +
            ".planarscene"), scene_asset);
        *asset = YAML::Load(scene_asset);
    }

    void SceneAsset::load(const std::string& scene_asset,
        const std::string& scene_name,
        const std::filesystem::path& asset_path)
    {
        name = scene_name;
        *asset = YAML::Load(scene_asset);
        path = asset_path;
    }

    void SceneAsset::save()
    {
        PLANAR_ASSERT_NOT_EMPTY(path);

        Core::FileSystem::create_file(path,
            Engine::Asset::to_string(*asset));
    }

    std::string SceneAsset::get_name() const
    {
        return name;
    }

    std::string SceneAsset::get_guid() const
    {
        return get_scalar("GUID");
    }

    YAML::Node SceneAsset::get_hierarchy()
    {
        return get("Hierarchy");
    }
}
