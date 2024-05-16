#pragma once

#include "Planar/Engine/Scene/Scene.hpp"
#include "Planar/Engine/UI/ImGui/ImGuiWindow.hpp"
#include "Planar/Engine/Graphics/Texture/Texture.hpp"
#include "Planar/Editor/UI/HierarchyWindow.hpp"
#include "Planar/Editor/UI/InspectorWindow.hpp"
#include "Planar/Editor/UI/SettingsWindow.hpp"
#include "Planar/Editor/UI/ContentWindow.hpp"
#include "Planar/Editor/UI/ConsoleWindow.hpp"
#include "Planar/Editor/UI/GameWindow.hpp"
#include "Planar/Editor/UI/SceneWindow.hpp"

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
        Planar::Editor::UI::HierarchyWindow hierarchy_window;
        Planar::Editor::UI::InspectorWindow inspector_window;
        Planar::Editor::UI::SettingsWindow settings_window;
        Planar::Editor::UI::ContentWindow content_window;
        Planar::Editor::UI::ConsoleWindow console_window;
        Planar::Editor::UI::GameWindow game_window;
        Planar::Editor::UI::SceneWindow scene_window;

        Planar::Engine::Graphics::Texture::Texture folder_texture;
        Planar::Engine::Graphics::Texture::Texture file_texture;

        void restore_default_layout() const;

        void render_main_menu_bar();
    };
}
