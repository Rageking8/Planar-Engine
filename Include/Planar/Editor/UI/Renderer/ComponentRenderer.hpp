#pragma once

#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>
#include <memory>

PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Core, Editor)
PLANAR_EDITOR_FORWARD_DECLARE_CLASS(UI::Container, ComponentStore)
PLANAR_ENGINE_FORWARD_DECLARE_CLASS(GameObject, GameObject)
PLANAR_ENGINE_FORWARD_DECLARE_CLASS(UI::ImGui::Menu, ContextMenu)

namespace Planar::Editor::UI::Renderer
{
    class ComponentRenderer
    {
    public:
        ComponentRenderer(Core::Editor* editor);

        void render(Container::ComponentStore& component_store,
            std::shared_ptr<Engine::GameObject::GameObject> game_object,
            Engine::UI::ImGui::Menu::ContextMenu* context_menu);

    private:
        Core::Editor* editor;
        bool context_menu_active;

        void render_context_menu(
            std::shared_ptr<Engine::GameObject::GameObject> game_object,
            Engine::UI::ImGui::Menu::ContextMenu* context_menu,
            std::string guid);
    };
}
