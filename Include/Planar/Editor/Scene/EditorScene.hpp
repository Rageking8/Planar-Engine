#pragma once

#include "Planar/Engine/Scene/Scene.hpp"
#include "Planar/Engine/UI/ImGui/ImGuiWindow.hpp"
#include "Planar/Engine/Graphics/Texture/Texture.hpp"
#include "Planar/Editor/UI/ContentWindow.hpp"

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
        Planar::Engine::UI::ImGui::ImGuiWindow hierarchy_window;
        Planar::Engine::UI::ImGui::ImGuiWindow inspector_window;
        Planar::Engine::UI::ImGui::ImGuiWindow settings_window;
        Planar::Editor::UI::ContentWindow content_window;
        Planar::Engine::UI::ImGui::ImGuiWindow console_window;
        Planar::Engine::UI::ImGui::ImGuiWindow game_window;
        Planar::Engine::UI::ImGui::ImGuiWindow scene_window;

        bool pending_restore_default_layout;

        Planar::Engine::Graphics::Texture::Texture folder_texture;
        Planar::Engine::Graphics::Texture::Texture file_texture;

        void restore_default_layout() const;

        void render_hierarchy_window();
        void render_inspector_window();
        void render_settings_window();
        void render_console_window();
        void render_game_window();
        void render_scene_window();

        void render_main_menu_bar();
    };
}
