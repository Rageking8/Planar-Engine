#include "Planar/Editor/Project/Project.hpp"
#include "Asset/Editor/PlanarEngine.h"
#include "Planar/Editor/Script/Init/Init.hpp"
#include "Planar/Engine/Core/Log/TerminalLogger.hpp"
#include "Planar/Engine/Asset/Asset.hpp"
#include "Planar/Engine/Asset/LoadAssetMacros.hpp"
#include "Planar/Engine/Core/Version.hpp"
#include "Planar/Engine/Core/GUID/GUID.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"

#include <filesystem>

PLANAR_LOAD_STD_STRING_ASSET(Editor::Project, Ignore)
PLANAR_LOAD_STD_STRING_ASSET(Editor::Project, Project)
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
            Planar::Engine::Core::FileSystem::select_folder_dialog();

        if (directory.empty())
        {
            Engine::Core::Log::TerminalLogger::get("Editor")->
                error("Invalid directory");

            return false;
        }

        if (!std::filesystem::exists(directory + L"/Project.planar"))
        {
            Engine::Core::Log::TerminalLogger::get("Editor")->
                error("No project file found");
            
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
            Engine::Core::Log::TerminalLogger::get("Editor")->
                error("Project name cannot be empty");

            return false;
        }

        std::wstring directory =
            Planar::Engine::Core::FileSystem::select_folder_dialog();

        if (directory.empty())
        {
            Engine::Core::Log::TerminalLogger::get("Editor")->
                error("Invalid directory");

            return false;
        }

        root_path = directory;
        this->project_name = project_name;

        Script::Init::verify_dotnet_sdk(root_path / "Cache");

        std::string main_scene_guid = create_main_scene();
        create_project_file(project_name, project_description,
            main_scene_guid);
        cs_project.create(root_path, project_name);

        std::filesystem::create_directories(root_path / "Build");

        create_engine_files();
        create_script_files();

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

    void Project::create_engine_files()
    {
        std::filesystem::path engine_path = root_path / "Engine";
        std::filesystem::create_directories(engine_path);

        std::filesystem::path planar_engine_dll_path =
            engine_path / "PlanarEngine.dll";
        Engine::Core::FileSystem::clear_file(planar_engine_dll_path);
        PLANAR_APPEND_ALL_CHUNKS_TO_FILE(planar_engine_dll_path,
            Editor, PlanarEngine)

        std::filesystem::path planar_script_dll_path =
            engine_path / "PlanarScript.dll";
        Engine::Core::FileSystem::clear_file(planar_script_dll_path);
        PLANAR_APPEND_ARRAY_TO_FILE(planar_script_dll_path,
            Editor::Script, PlanarScript)

        Engine::Core::FileSystem::create_file(
            engine_path / "GeneratedEntry.cs",
            Asset::Editor::Script::GeneratedEntry);
    }

    void Project::create_script_files()
    {
        std::filesystem::path scripts_path = root_path / "Scripts";
        std::filesystem::create_directories(scripts_path);
    }
}
