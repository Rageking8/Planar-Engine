#include "Planar/Editor/Project/Project.hpp"
#include "Asset/Editor/PlanarEngine.h"
#include "Planar/Editor/Script/Init/Init.hpp"
#include "Planar/Engine/Core/Log/TerminalLogger.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"
#include "Planar/Editor/Core/VisualStudio/VisualStudio.hpp"
#include "Planar/Engine/Asset/AssetFunction.hpp"
#include "Planar/Engine/Asset/LoadAssetMacros.hpp"

PLANAR_LOAD_STD_STRING_ASSET(Editor::Project, Ignore)
PLANAR_LOAD_STD_STRING_ASSET(Editor::Project, Scene)
PLANAR_LOAD_STD_STRING_ASSET(Editor::Script, GeneratedEntry)
PLANAR_LOAD_UNSIGNED_CHAR_ARRAY_ASSET(Editor::Script,
    PlanarScript)
PLANAR_LOAD_UNSIGNED_CHAR_ARRAY_ASSET_ALL_CHUNKS(
    Editor, PlanarEngine)

namespace Planar::Editor::Project
{
    Project::Project()
    {

    }

    bool Project::open_project()
    {
        std::wstring directory =
            Engine::Core::FileSystem::select_folder_dialog();

        if (directory.empty())
        {
            Engine::Core::Log::TerminalLogger::get("Editor")->
                error("Invalid directory");

            return false;
        }

        unsigned project_asset_count =
            Engine::Core::FileSystem::file_count_with_extension(
            directory, "planar");
        if (project_asset_count == 0)
        {
            Engine::Core::Log::TerminalLogger::get("Editor")->
                error("No project asset found");

            return false;
        }
        else if (project_asset_count > 1)
        {
            Engine::Core::Log::TerminalLogger::get("Editor")->
                error("More than 1 project asset found");

            return false;
        }

        root_path = directory;
        std::filesystem::path project_asset_path =
            Engine::Core::FileSystem::first_file_with_extension(
            root_path, "planar");
        project_name = Engine::Asset::get_value(
            Engine::Core::FileSystem::read_file(
            project_asset_path), "Name");

        cs_project.load(project_name, root_path);

        return true;
    }

    bool Project::create_project(const std::string& project_name,
        const std::string& project_description,
        bool create_gitignore,
        const Core::Progress::ProgressHandler& progress_handler)
    {
        unsigned tasks;
        return create_project(false, tasks, project_name,
            project_description, create_gitignore, progress_handler);
    }

    unsigned Project::create_project_tasks(
        const std::string& project_name,
        const std::string& project_description,
        bool create_gitignore)
    {
        unsigned tasks = 0;
        create_project(true, tasks, project_name, project_description,
            create_gitignore);

        return tasks;
    }

    std::filesystem::path Project::get_root_path() const
    {
        return root_path;
    }

    std::string Project::get_project_name() const
    {
        return project_name;
    }

    bool Project::create_project(bool dry_run, unsigned& tasks,
        const std::string& project_name,
        const std::string& project_description, bool create_gitignore,
        const Core::Progress::ProgressHandler& progress_handler)
    {
        tasks = 0;

        if (!dry_run && project_name.empty())
        {
            Engine::Core::Log::TerminalLogger::get("Editor")->
                error("Project name cannot be empty");

            return false;
        }

        std::wstring directory;
        if (!dry_run)
        {
            directory =
                Engine::Core::FileSystem::select_folder_dialog();
        }

        if (!dry_run && directory.empty())
        {
            Engine::Core::Log::TerminalLogger::get("Editor")->
                error("Invalid directory");

            return false;
        }

        root_path = directory;
        this->project_name = project_name;

        dry_run_helper([&]
            {
                Script::Init::verify_dotnet_sdk(root_path / "Cache",
                    progress_handler);
            }, dry_run, tasks, 2);

        dry_run_helper([&]
            {
                progress_handler("Creating main scene asset");
                scene_asset.create(Asset::Editor::Project::Scene,
                    root_path / "Scenes", "MainScene");
                progress_handler();
            }, dry_run, tasks);

        dry_run_helper([&]
            {
                progress_handler("Creating project asset");
                project_asset.create(root_path, project_name,
                    project_description, scene_asset.get_guid());
                progress_handler();
            }, dry_run, tasks);

        dry_run_helper([&]
            {
                progress_handler("Creating C# project");
                cs_project.create(project_name, root_path);
                progress_handler();
            }, dry_run, tasks);

        dry_run_helper([&]
            {
                Core::VisualStudio::create_solution_file(
                    root_path, root_path / "Cache" / "DotnetSDK" /
                    "dotnet.exe", cs_project, progress_handler);
            }, dry_run, tasks, 2);

        dry_run_helper([&]
            {
                progress_handler("Creating build folder");
                std::filesystem::create_directories(root_path / "Build");
                progress_handler();
            }, dry_run, tasks);

        dry_run_helper([&]
            {
                create_engine_files(progress_handler);
            }, dry_run, tasks, 4);

        dry_run_helper([&]
            {
                create_script_files(progress_handler);
            }, dry_run, tasks);

        if (create_gitignore && !dry_run)
        {
            progress_handler("Writing .gitignore file");
            Engine::Core::FileSystem::create_file(
                root_path / ".gitignore",
                Planar::Asset::Editor::Project::Ignore);
            progress_handler();
        }
        else if (create_gitignore && dry_run)
        {
            tasks += 1;
        }

        return true;
    }

    void Project::create_engine_files(
        const Core::Progress::ProgressHandler& progress_handler)
    {
        progress_handler("Creating engine folder");
        std::filesystem::path engine_path = root_path / "Engine";
        std::filesystem::create_directories(engine_path);
        progress_handler();

        progress_handler("Writing PlanarEngine.dll");
        std::filesystem::path planar_engine_dll_path =
            engine_path / "PlanarEngine.dll";
        Engine::Core::FileSystem::clear_file(planar_engine_dll_path);
        PLANAR_APPEND_ALL_CHUNKS_TO_FILE(planar_engine_dll_path,
            Editor, PlanarEngine)
        progress_handler();

        progress_handler("Writing PlanarScript.dll");
        std::filesystem::path planar_script_dll_path =
            engine_path / "PlanarScript.dll";
        Engine::Core::FileSystem::clear_file(planar_script_dll_path);
        PLANAR_APPEND_ARRAY_TO_FILE(planar_script_dll_path,
            Editor::Script, PlanarScript)
        progress_handler();

        progress_handler("Writing GeneratedEntry.cs");
        Engine::Core::FileSystem::create_file(
            engine_path / "GeneratedEntry.cs",
            Planar::Asset::Editor::Script::GeneratedEntry);
        progress_handler();
    }

    void Project::create_script_files(
        const Core::Progress::ProgressHandler& progress_handler)
    {
        progress_handler("Creating scripts folder");
        std::filesystem::path scripts_path = root_path / "Scripts";
        std::filesystem::create_directories(scripts_path);
        progress_handler();
    }

    void Project::dry_run_helper(const std::function<void()> run,
        bool dry_run, unsigned& tasks, unsigned amount)
    {
        if (!dry_run)
        {
            run();
        }
        else
        {
            tasks += amount;
        }
    }
}
