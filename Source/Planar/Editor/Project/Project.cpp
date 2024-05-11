#include "Planar/Editor/Project/Project.hpp"
#include "Planar/Engine/Asset/Asset.hpp"
#include "Planar/Engine/Asset/LoadAssetMacros.hpp"
#include "Planar/Engine/Core/Version.hpp"
#include "Planar/Engine/Core/GUID/GUID.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"

#include <iostream>
#include <fstream>

PLANAR_LOAD_STD_STRING_ASSET(Editor, Project)

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

        return true;
    }

    bool Project::create_project(const std::string& project_name,
        const std::string& project_description)
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

        create_project_file(project_name, project_description);

        return true;
    }

    void Project::create_project_file(const std::string& project_name,
        const std::string& project_description)
    {
        std::ofstream output(root_path / "Project.planar");

        output << Planar::Engine::Asset::preprocess_asset_scalar(
            Planar::Engine::Asset::preprocess_asset_meta(
            Planar::Asset::Editor::Project),
            {
                { "<GUID>", Planar::Engine::Core::GUID::generate_guid(
                    Planar::Engine::Core::GUID::Representation::
                    DEFAULT_COMPACT) },

                { "<VERSION>", Planar::Engine::Core::VERSION },

                { "<NAME>", project_name },

                { "<DESCRIPTION>", project_description },
            });
    }
}
