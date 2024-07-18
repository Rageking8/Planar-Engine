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
        Asset::load(scene_asset);
    }

    void SceneAsset::load(const std::string& scene_name,
        const std::string& asset_string)
    {
        name = scene_name;
        Asset::load(asset_string);
    }

    void SceneAsset::load(const std::filesystem::path& scene_path)
    {
        name = scene_path.stem().string();
        Asset::load(scene_path);
        path = scene_path;
    }

    void SceneAsset::reload_from_path()
    {
        Asset::load(path);
    }

    void SceneAsset::save()
    {
        write(path);
    }

    std::string SceneAsset::get_name() const
    {
        return name;
    }

    std::string SceneAsset::get_guid() const
    {
        return get_value<std::string>("GUID");
    }

    YAML::Node SceneAsset::get_hierarchy()
    {
        return get("Hierarchy");
    }
}
