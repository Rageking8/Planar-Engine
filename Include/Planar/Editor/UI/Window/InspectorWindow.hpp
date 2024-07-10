#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"
#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"
#include "Planar/Editor/UI/Container/ComponentStore.hpp"
#include "Planar/Editor/UI/Renderer/ComponentRenderer.hpp"
#include "Planar/Engine/UI/ImGui/Element/InputField.hpp"
#include "Planar/Engine/UI/ImGui/Menu/ContextMenu.hpp"

PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Core, Editor)
PLANAR_EDITOR_FORWARD_DECLARE_ENUM_CLASS(Core::Select, SelectType)

namespace Planar::Editor::UI::Window
{
    class InspectorWindow : public EditorWindow
    {
    public:
        InspectorWindow(Core::Editor* editor);

        void init();
        void update();

        virtual void render_window() override;

        template <typename ComponentT>
        void add_component();

    private:
        Engine::UI::ImGui::Element::InputField name_input;
        Container::ComponentStore component_store;
        Renderer::ComponentRenderer component_renderer;
        Engine::UI::ImGui::Menu::ContextMenu context_menu;

        void handle_select(Core::Select::SelectType select_type);
    };
}

#include "Planar/Editor/UI/Window/InspectorWindow.tpp"
