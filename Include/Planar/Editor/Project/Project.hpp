#pragma once

#include <string>
#include <filesystem>

namespace Planar::Editor::Project
{
    class Project
    {
    public:
        Project();

        bool open_project();
        bool create_project(const std::string& project_name,
            const std::string& project_description);

    private:
        std::filesystem::path root_path;
    };
}
