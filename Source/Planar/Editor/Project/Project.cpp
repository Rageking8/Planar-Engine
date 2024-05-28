#include "Planar/Editor/Project/Project.hpp"
#include "Planar/Engine/Asset/Asset.hpp"
#include "Planar/Engine/Asset/LoadAssetMacros.hpp"
#include "Planar/Engine/Core/Version.hpp"
#include "Planar/Engine/Core/GUID/GUID.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"

#include <iostream>
#include <filesystem>

PLANAR_LOAD_STD_STRING_ASSET(Editor::Project, Ignore)
PLANAR_LOAD_STD_STRING_ASSET(Editor::Project, Project)
PLANAR_LOAD_STD_STRING_ASSET(Editor::Project, Scene)

namespace Planar::Editor::Project
{
    Project::Project()
    {

    }

    bool Project::open_project()
    {
        std::wstring directory =
            Planar::Engine::Core::FileSystem::select_folder_dialog();

        if (directory.empty())
        {
            std::cout << "Invalid directory\n";

            return false;
        }

        if (!std::filesystem::exists(directory + L"/Project.planar"))
        {
            std::cout << "No project file found\n";
            
            return false;
        }

        root_path = directory;
        project_name = Planar::Engine::Asset::get_value(
            Planar::Engine::Core::FileSystem::read_file(
            directory + L"/Project.planar"), "Name");

        return true;
    }

    bool Project::create_project(const std::string& project_name,
        const std::string& project_description, bool create_gitignore)
    {
        if (project_name.empty())
        {
            std::cout << "Project name cannot be empty\n";

            return false;
        }

        std::wstring directory =
            Planar::Engine::Core::FileSystem::select_folder_dialog();

        if (directory.empty())
        {
            std::cout << "Invalid directory\n";

            return false;
        }

        root_path = directory;
        this->project_name = project_name;

        std::string main_scene_guid = create_main_scene();
        create_project_file(project_name, project_description,
            main_scene_guid);

        std::filesystem::create_directories(root_path / "Build");

        if (create_gitignore)
        {
            Planar::Engine::Core::FileSystem::create_file(
                root_path / ".gitignore",
                Planar::Asset::Editor::Project::Ignore);
        }

        return true;
    }

    std::filesystem::path Project::get_root_path() const
    {
        return root_path;
    }

    std::string Project::get_project_name() const
    {
        return project_name;
    }

    void Project::create_project_file(const std::string& project_name,
        const std::string& project_description,
        const std::string& main_scene_guid)
    {
        Planar::Engine::Core::FileSystem::create_file(
            root_path / "Project.planar",
            Planar::Engine::Asset::preprocess_asset_scalar(
            Planar::Engine::Asset::preprocess_asset_meta(
            Planar::Asset::Editor::Project::Project),
            {
                { "<VERSION>", Planar::Engine::Core::VERSION },

                { "<GUID>", Planar::Engine::Core::GUID::generate_guid(
                    Planar::Engine::Core::GUID::Representation::
                    DEFAULT_COMPACT) },

                { "<NAME>", project_name },

                { "<DESCRIPTION>", project_description },

                { "<MAIN_SCENE_GUID>", main_scene_guid },
            }));
    }

    std::string Project::create_main_scene()
    {
        std::string main_scene_guid =
            Planar::Engine::Core::GUID::generate_guid(
            Planar::Engine::Core::GUID::Representation::DEFAULT_COMPACT);

        Planar::Engine::Core::FileSystem::create_file(
            root_path / "Scenes/MainScene.planarscene",
            Planar::Engine::Asset::preprocess_asset_scalar(
            Planar::Engine::Asset::preprocess_asset_meta(
            Planar::Asset::Editor::Project::Scene),
            {
                { "<VERSION>", Planar::Engine::Core::VERSION },

                { "<GUID>", main_scene_guid },
            }));

        return main_scene_guid;
    }
}
