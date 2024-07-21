#include "Planar/Editor/Project/Project.hpp"
#include "Planar/Editor/Script/Init/Init.hpp"
#include "Planar/Editor/Core/Progress/Progress.hpp"
#include "Planar/Editor/Core/VisualStudio/VisualStudio.hpp"
#include "Planar/Engine/Core/Log/TerminalLogger.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"
#include "Planar/Engine/Core/FileSystem/SelectDialogResult.hpp"
#include "Planar/Engine/Asset/AssetFunction.hpp"
#include "Planar/Engine/Asset/LoadAssetMacros.hpp"

PLANAR_LOAD_STD_STRING_ASSET(Editor::Project, Ignore)
PLANAR_LOAD_STD_STRING_ASSET(Editor::Project, Scene)
PLANAR_LOAD_STD_STRING_ASSET(Editor::Script, GeneratedEntry)
PLANAR_LOAD_UNSIGNED_CHAR_ARRAY_ASSET(Editor::Script, PlanarScript)
PLANAR_LOAD_UNSIGNED_CHAR_ARRAY_ASSET(Editor, PlanarEngine)

namespace Planar::Editor::Project
{
    Project::Project()
    {

    }

    bool Project::open_project()
    {
        Engine::Core::FileSystem::SelectDialogResult result =
            Engine::Core::FileSystem::select_folder_dialog();

        if (!result)
        {
            if (result.has_error())
            {
                Engine::Core::Log::TerminalLogger::get("Editor")->
                    error(result.get_error());
            }

            return false;
        }

        const std::filesystem::path path = result.get_path();

        unsigned project_asset_count =
            Engine::Core::FileSystem::file_count_with_extension(
            path, "planar");
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

        root_path = path;
        std::filesystem::path project_asset_path =
            Engine::Core::FileSystem::first_file_with_extension(
            root_path, "planar");
        project_name = Engine::Asset::get_value(
            Engine::Core::FileSystem::read_file(
            project_asset_path), "Name");

        cs_project.load(project_name, root_path);

        create_engine_files({});

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

    const Script::CSProject& Project::get_cs_project() const
    {
        return cs_project;
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

        if (!dry_run)
        {
            Engine::Core::FileSystem::SelectDialogResult result =
                Engine::Core::FileSystem::select_folder_dialog();

            if (!result)
            {
                if (result.has_error())
                {
                    Engine::Core::Log::TerminalLogger::get("Editor")->
                        error(result.get_error());
                }

                return false;
            }

            root_path = result.get_path();
            this->project_name = project_name;
        }

        Core::Progress::task([&]
            {
                Script::Init::verify_dotnet_sdk(root_path / "Cache",
                    progress_handler);
            }, dry_run, tasks, 2);

        Core::Progress::task("Creating main scene asset", [&]
            {
                scene_asset.create(Asset::Editor::Project::Scene,
                    root_path / "Scenes", "MainScene");
            }, progress_handler, dry_run, tasks);

        Core::Progress::task("Creating project asset", [&]
            {
                project_asset.create(root_path, project_name,
                    project_description, scene_asset.get_guid());
            }, progress_handler, dry_run, tasks);

        Core::Progress::task("Creating C# project", [&]
            {
                cs_project.create(project_name, root_path);
            }, progress_handler, dry_run, tasks);

        Core::Progress::task([&]
            {
                Core::VisualStudio::create_solution_file(
                    root_path, root_path / "Cache" / "DotnetSDK" /
                    "dotnet.exe", cs_project, progress_handler);
            }, dry_run, tasks, 2);

        Core::Progress::task("Creating build folder", [&]
            {
                std::filesystem::create_directories(root_path /
                    "Build");
            }, progress_handler, dry_run, tasks);

        Core::Progress::task([&]
            {
                create_engine_files(progress_handler);
            }, dry_run, tasks, 4);

        Core::Progress::task([&]
            {
                create_script_files(progress_handler);
            }, dry_run, tasks);

        Core::Progress::task([&]
            {
                create_texture_files(progress_handler);
            }, dry_run, tasks);

        if (create_gitignore)
        {
            Core::Progress::task("Writing .gitignore file", [&]
                {
                    Engine::Core::FileSystem::create_file(
                        root_path / ".gitignore",
                        Planar::Asset::Editor::Project::Ignore);
                }, progress_handler, dry_run, tasks);
        }

        return true;
    }

    void Project::create_engine_files(
        const Core::Progress::ProgressHandler& progress_handler) const
    {
        progress_handler("Creating engine folder");
        const std::filesystem::path engine_path = root_path / "Engine";
        std::filesystem::create_directories(engine_path);
        progress_handler();

        progress_handler("Writing PlanarEngine.dll");
        const std::filesystem::path planar_engine_dll_path =
            engine_path / "PlanarEngine.dll";
        Engine::Core::FileSystem::clear_file(planar_engine_dll_path);
        PLANAR_APPEND_ARRAY_TO_FILE(planar_engine_dll_path,
            Editor, PlanarEngine)
        progress_handler();

        progress_handler("Writing PlanarScript.dll");
        const std::filesystem::path planar_script_dll_path =
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
        const Core::Progress::ProgressHandler& progress_handler) const
    {
        progress_handler("Creating scripts folder");
        const std::filesystem::path scripts_path =
            root_path / "Scripts";
        std::filesystem::create_directories(scripts_path);
        progress_handler();
    }

    void Project::create_texture_files(
        const Core::Progress::ProgressHandler& progress_handler) const
    {
        progress_handler("Creating textures folder");
        const std::filesystem::path textures_path =
            root_path / "Textures";
        std::filesystem::create_directories(textures_path);
        progress_handler();
    }
}
