#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"
#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"
#include "Planar/Engine/UI/ImGui/Element/Tree.hpp"
#include "Planar/Engine/UI/ImGui/Menu/ContextMenu.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <memory>

PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Core, Editor)
PLANAR_ENGINE_FORWARD_DECLARE_CLASS(GameObject, GameObject)

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

        void render_scene_game_object(
            std::shared_ptr<Engine::GameObject::GameObject> game_object);
        void render_scene_children(
            std::shared_ptr<Engine::GameObject::GameObject> game_object);
        void render_context_menu(
            std::shared_ptr<Engine::GameObject::GameObject> game_object);

        void handle_select(
            std::shared_ptr<Engine::GameObject::GameObject> game_object);
    };
}
