#pragma once

#include "Planar/Editor/Script/CSProject.hpp"
#include "Planar/Editor/Core/Progress/Progress.hpp"

#include <string>
#include <functional>
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
            bool create_gitignore,
            const Core::Progress::ProgressHandler& progress_handler);
        unsigned create_project_tasks(const std::string& project_name,
            const std::string& project_description, bool create_gitignore);

        std::filesystem::path get_root_path() const;
        std::string get_project_name() const;

    private:
        std::filesystem::path root_path;
        std::string project_name;
        Script::CSProject cs_project;

        bool create_project(bool dry_run, unsigned& tasks,
            const std::string& project_name,
            const std::string& project_description,
            bool create_gitignore,
            const Core::Progress::ProgressHandler& progress_handler = {});
        void create_project_file(const std::string& project_name,
            const std::string& project_description,
            const std::string& main_scene_guid);

        std::string create_main_scene();
        void create_engine_files(
            const Core::Progress::ProgressHandler& progress_handler);
        void create_script_files(
            const Core::Progress::ProgressHandler& progress_handler);

        void dry_run_helper(const std::function<void()> run,
            bool dry_run, unsigned& tasks, unsigned amount = 1);
    };
}
