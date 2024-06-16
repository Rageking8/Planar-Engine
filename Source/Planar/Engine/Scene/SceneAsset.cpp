#include "Planar/Engine/Scene/SceneAsset.hpp"
#include "Planar/Engine/Asset/AssetFunction.hpp"
#include "Planar/Engine/Core/Version.hpp"
#include "Planar/Engine/Core/GUID/GUID.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"

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
                { "<VERSION>", Core::VERSION },

                { "<GUID>", Core::GUID::generate_guid(
                    Core::GUID::Representation::DEFAULT_COMPACT) },
            });

        Core::FileSystem::create_file(path / (scene_name +
            ".planarscene"), scene_asset);
        asset = YAML::Load(scene_asset);
    }

    void SceneAsset::load(const std::string& scene_asset,
        const std::string& scene_name)
    {
        name = scene_name;
        asset = YAML::Load(scene_asset);
    }

    std::string SceneAsset::get_name() const
    {
        return name;
    }

    std::string SceneAsset::get_guid() const
    {
        return asset["GUID"].Scalar();
    }

    YAML::Node SceneAsset::get_hierarchy()
    {
        return asset["Hierarchy"];
    }
}
