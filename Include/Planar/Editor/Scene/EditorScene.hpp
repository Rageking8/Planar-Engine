#pragma once

#include "Planar/Engine/Scene/Scene.hpp"
#include "Planar/Engine/Graphics/Texture/Texture.hpp"
#include "Planar/Editor/UI/Window/HierarchyWindow.hpp"
#include "Planar/Editor/UI/Window/InspectorWindow.hpp"
#include "Planar/Editor/UI/Window/SettingsWindow.hpp"
#include "Planar/Editor/UI/Window/ContentWindow.hpp"
#include "Planar/Editor/UI/Window/ConsoleWindow.hpp"
#include "Planar/Editor/UI/Window/GameWindow.hpp"
#include "Planar/Editor/UI/Window/SceneWindow.hpp"

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

    private:
        Planar::Editor::UI::Window::HierarchyWindow hierarchy_window;
        Planar::Editor::UI::Window::InspectorWindow inspector_window;
        Planar::Editor::UI::Window::SettingsWindow settings_window;
        Planar::Editor::UI::Window::ContentWindow content_window;
        Planar::Editor::UI::Window::ConsoleWindow console_window;
        Planar::Editor::UI::Window::GameWindow game_window;
        Planar::Editor::UI::Window::SceneWindow scene_window;

        Planar::Engine::Graphics::Texture::Texture file_texture;
        Planar::Engine::Graphics::Texture::Texture folder_texture;

        void restore_default_layout() const;

        void render_main_menu_bar();
    };
}
