#pragma once

#include "Planar/Engine/Math/Size2D.hpp"
#include "Planar/Engine/Core/Application.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"
#include "Planar/Editor/Project/Project.hpp"
#include "Planar/Editor/Core/EditorGameMode.hpp"
#include "Planar/Editor/Core/Save/SaveHandler.hpp"
#include "Planar/Editor/Core/Select/SelectHandler.hpp"
#include "Planar/Editor/Core/Input/InputHandler.hpp"
#include "Planar/Editor/Core/Console/CommandLineProcessor.hpp"
#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>
#include <memory>
#include <functional>
#include <filesystem>

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Scene, Scene)
PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Scene, EditorScene)

namespace Planar::Editor::Core
{
    class Editor : public Engine::Core::Application
    {
    public:
        Editor();
        Editor(int argc, char* argv[]);
        virtual ~Editor();

        // Process command line arguments before initializing
        // and running the editor. The return value will be
        // propagated to `main`.
        int start();

        virtual bool init() override;

        virtual Engine::Math::Size2Di get_game_framebuffer_size()
            const override;

        void enter_editor();

        void change_scene(
            std::unique_ptr<Engine::Scene::Scene> new_scene);
        void update_window_name(const std::string& scene_name = "",
            bool show_asterisk = false);

        void set_window_asterisk(bool show);

        Project::Project& get_project();

        std::unique_ptr<Engine::Scene::Scene>& get_current_scene();
        void new_current_scene(
            const std::filesystem::path& scene_path);
        void close_current_scene();

        Scene::EditorScene* get_editor_scene() const;

        void add_save_callback(const std::string& name,
            const std::function<void()>& save_callback);

        void set_dirty(bool skip_if_editor_game_playing = true);
        void save_all(bool skip_if_editor_game_playing = true);

        Select::SelectHandler& get_select_handler();

        EditorGameMode get_editor_game_mode() const;
        void set_editor_game_mode(
            EditorGameMode new_editor_game_mode);

        std::filesystem::path get_current_content_path() const;
        void set_current_content_path(
            const std::filesystem::path& new_current_content_path);

        void set_game_content_size(
            Engine::Math::Size2Di new_game_content_size);

    private:
        Console::CommandLineProcessor command_line_processor;
        Project::Project project;
        std::unique_ptr<Engine::Scene::Scene> current_scene;
        Save::SaveHandler save_handler;
        Select::SelectHandler select_handler;
        Input::InputHandler input_handler;
        EditorGameMode editor_game_mode;
        std::filesystem::path current_content_path;

        Engine::Math::Size2Di game_content_size;

        std::unique_ptr<Engine::Scene::Scene> editor_main_scene;

        void reset_on_exit_play_mode();

        virtual void update_impl() override;
    };
}
