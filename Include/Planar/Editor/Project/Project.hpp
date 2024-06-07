#pragma once

#include "Planar/Editor/Script/CSProject.hpp"

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
            const std::string& project_description,
            bool create_gitignore);

        std::filesystem::path get_root_path() const;
        std::string get_project_name() const;

    private:
        std::filesystem::path root_path;
        std::string project_name;
        Script::CSProject cs_project;

        void create_project_file(const std::string& project_name,
            const std::string& project_description,
            const std::string& main_scene_guid);

        std::string create_main_scene();
        void create_engine_files();
        void create_script_files();
    };
}
