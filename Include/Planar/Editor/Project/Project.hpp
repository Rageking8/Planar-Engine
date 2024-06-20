#pragma once

#include "Planar/Editor/Project/ProjectAsset.hpp"
#include "Planar/Editor/Core/Progress/ProgressHandler.hpp"
#include "Planar/Editor/Script/CSProject.hpp"
#include "Planar/Engine/Scene/SceneAsset.hpp"

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
            bool create_gitignore,
            const Core::Progress::ProgressHandler& progress_handler);
        unsigned create_project_tasks(const std::string& project_name,
            const std::string& project_description, bool create_gitignore);

        std::filesystem::path get_root_path() const;
        std::string get_project_name() const;
        const Script::CSProject& get_cs_project() const;

    private:
        std::filesystem::path root_path;
        std::string project_name;
        Script::CSProject cs_project;
        ProjectAsset project_asset;
        Engine::Scene::SceneAsset scene_asset;

        bool create_project(bool dry_run, unsigned& tasks,
            const std::string& project_name,
            const std::string& project_description,
            bool create_gitignore,
            const Core::Progress::ProgressHandler& progress_handler = {});

        void create_engine_files(const Core::Progress::ProgressHandler&
            progress_handler) const;
        void create_script_files(const Core::Progress::ProgressHandler&
            progress_handler) const;
    };
}
