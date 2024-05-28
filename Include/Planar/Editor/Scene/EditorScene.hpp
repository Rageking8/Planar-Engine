#pragma once

#include "Planar/Engine/Scene/Scene.hpp"
#include "Planar/Engine/Graphics/OpenGL/Texture/Texture2D.hpp"
#include "Planar/Editor/UI/Window/HierarchyWindow.hpp"
#include "Planar/Editor/UI/Window/InspectorWindow.hpp"
#include "Planar/Editor/UI/Window/SettingsWindow.hpp"
#include "Planar/Editor/UI/Window/ContentWindow.hpp"
#include "Planar/Editor/UI/Window/ConsoleWindow.hpp"
#include "Planar/Editor/UI/Window/GameWindow.hpp"
#include "Planar/Editor/UI/Window/SceneWindow.hpp"
#include "Planar/Editor/UI/Window/BuildWindow.hpp"
#include "Planar/Editor/Project/Project.hpp"

namespace Planar::Editor::Scene
{
    class EditorScene :
        public Planar::Engine::Scene::Scene
    {
    public:
        EditorScene();

        virtual void init() override;
        virtual void update() override;
        virtual void render() override;

        void set_project(Planar::Editor::Project::Project* new_project);

    private:
        Planar::Editor::UI::Window::HierarchyWindow hierarchy_window;
        Planar::Editor::UI::Window::InspectorWindow inspector_window;
        Planar::Editor::UI::Window::SettingsWindow settings_window;
        Planar::Editor::UI::Window::ContentWindow content_window;
        Planar::Editor::UI::Window::ConsoleWindow console_window;
        Planar::Editor::UI::Window::GameWindow game_window;
        Planar::Editor::UI::Window::SceneWindow scene_window;
        Planar::Editor::UI::Window::BuildWindow build_window;

        Planar::Engine::Graphics::OpenGL::Texture::Texture2D
            file_texture;
        Planar::Engine::Graphics::OpenGL::Texture::Texture2D
            folder_texture;
        Planar::Engine::Graphics::OpenGL::Texture::Texture2D
            left_arrow_texture;

        Planar::Editor::Project::Project* project;

        void restore_default_layout() const;

        void load_icons();

        void render_main_menu_bar();
    };
}
