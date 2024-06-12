#pragma once

#include "Planar/Editor/Scene/Scene.hpp"
#include "Planar/Editor/UI/Window/HierarchyWindow.hpp"
#include "Planar/Editor/UI/Window/InspectorWindow.hpp"
#include "Planar/Editor/UI/Window/SettingsWindow.hpp"
#include "Planar/Editor/UI/Window/ContentWindow.hpp"
#include "Planar/Editor/UI/Window/ConsoleWindow.hpp"
#include "Planar/Editor/UI/Window/GameWindow.hpp"
#include "Planar/Editor/UI/Window/SceneWindow.hpp"
#include "Planar/Editor/UI/Window/BuildWindow.hpp"
#include "Planar/Engine/Graphics/OpenGL/Texture/Texture2D.hpp"

namespace Planar::Editor::Scene
{
    class EditorScene : public Scene
    {
    public:
        EditorScene();

        virtual void init() override;
        virtual void update() override;
        virtual void render() override;

    private:
        UI::Window::HierarchyWindow hierarchy_window;
        UI::Window::InspectorWindow inspector_window;
        UI::Window::SettingsWindow settings_window;
        UI::Window::ContentWindow content_window;
        UI::Window::ConsoleWindow console_window;
        UI::Window::GameWindow game_window;
        UI::Window::SceneWindow scene_window;
        UI::Window::BuildWindow build_window;

        Engine::Graphics::OpenGL::Texture::Texture2D file_texture;
        Engine::Graphics::OpenGL::Texture::Texture2D folder_texture;
        Engine::Graphics::OpenGL::Texture::Texture2D left_arrow_texture;

        void restore_default_layout() const;

        void load_icons();

        void render_main_menu_bar();
    };
}
