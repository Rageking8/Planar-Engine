#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"
#include "Planar/Engine/UI/ImGui/Element/Tree.hpp"
#include "Planar/Engine/UI/ImGui/Menu/ContextMenu.hpp"
#include "Planar/Engine/Scene/SceneNode.hpp"
#include "Planar/Engine/Core/GameObject.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

PLANAR_FORWARD_DECLARE_CLASS(Editor::Core, Editor)

namespace Planar::Editor::UI::Window
{
    class HierarchyWindow : public EditorWindow
    {
    public:
        HierarchyWindow(Core::Editor* editor);

        virtual void render_window() override;

    private:
        Engine::UI::ImGui::Element::Tree hierarchy_tree;
        Engine::UI::ImGui::Menu::ContextMenu context_menu;
        bool context_menu_active;

        void render_scene_node(Engine::Scene::SceneNode& scene_node);
        void render_scene_node_children(
            Engine::Scene::SceneNode& scene_node);
        void render_context_menu(
            Engine::Scene::SceneNode& scene_node);

        void handle_select(
            Engine::Core::GameObject* current_game_object);
    };
}
