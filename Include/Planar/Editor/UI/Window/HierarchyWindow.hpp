#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"
#include "Planar/Engine/UI/ImGui/Element/Tree.hpp"
#include "Planar/Engine/UI/ImGui/Menu/ContextMenu.hpp"
#include "Planar/Engine/Scene/SceneNode.hpp"

namespace Planar::Editor::UI::Window
{
    class HierarchyWindow : public EditorWindow
    {
    public:
        HierarchyWindow();

        virtual void render_window() override;

    private:
        Engine::UI::ImGui::Element::Tree hierarchy_tree;
        Engine::UI::ImGui::Menu::ContextMenu context_menu;
        bool context_menu_active;

        void render_scene_node(Engine::Scene::SceneNode& scene_node);
    };
}
