#include "Planar/Editor/Project/ProjectAsset.hpp"
#include "Planar/Engine/Core/Version.hpp"
#include "Planar/Engine/Core/GUID/GUID.hpp"
#include "Planar/Engine/Asset/AssetFunction.hpp"
#include "Planar/Engine/Asset/LoadAssetMacros.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"

PLANAR_LOAD_STD_STRING_ASSET(Editor::Project, Project)

namespace Planar::Editor::Project
{
    ProjectAsset::ProjectAsset()
    {

    }

    void ProjectAsset::create(const std::filesystem::path& path,
        const std::string& project_name,
        const std::string& project_description,
        const std::string& main_scene_guid)
    {
        asset = Engine::Asset::preprocess_asset(
        Planar::Asset::Editor::Project::Project,
        {
            { "<VERSION>", Engine::Core::VERSION },

            { "<GUID>", Engine::Core::GUID::generate_guid(
                Engine::Core::GUID::Representation::
                DEFAULT_COMPACT) },

            { "<NAME>", project_name },

            { "<DESCRIPTION>", project_description },

            { "<MAIN_SCENE_GUID>", main_scene_guid },
        });

        Engine::Core::FileSystem::create_file(
            path / (project_name + ".planar"), asset);
    }
}
