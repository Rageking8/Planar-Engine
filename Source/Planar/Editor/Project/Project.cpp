#include "Planar/Editor/Project/Project.hpp"
#include "Planar/Engine/Asset/Asset.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"

#include <iostream>

namespace Planar::Editor::Project
{
    Project::Project()
    {

    }

    bool Project::open_project()
    {
        std::wstring directory =
            Planar::Engine::Core::FileSystem::SelectFolderDialog();

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
            Planar::Engine::Core::FileSystem::SelectFolderDialog();

        if (directory.empty())
        {
            std::cout << "Invalid directory\n";

            return false;
        }

        Planar::Engine::Asset::create_project_file(project_name,
            project_description, directory);

        root_path = directory;

        return true;
    }
}
