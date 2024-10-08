#pragma once

#include "Planar/Editor/UI/Window/Core/EditorWindow.hpp"
#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"
#include "Planar/Editor/UI/Container/ComponentStore.hpp"
#include "Planar/Editor/UI/Renderer/ComponentRenderer.hpp"
#include "Planar/Engine/UI/ImGui/Element/InputField.hpp"
#include "Planar/Engine/UI/ImGui/Element/Checkbox.hpp"
#include "Planar/Engine/UI/ImGui/Menu/ContextMenu.hpp"

PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Core, Editor)
PLANAR_EDITOR_FORWARD_DECLARE_ENUM_CLASS(Core::Select, SelectType)

namespace Planar::Editor::UI::Window
{
    class InspectorWindow : public Core::EditorWindow
    {
    public:
        InspectorWindow(Editor::Core::Editor* editor);

        virtual void init() override;
        virtual void update() override;

        virtual void render_window() override;

        template <typename ComponentT, typename... Args>
        void add_component(Args&... args);

    private:
        Engine::UI::ImGui::Element::Checkbox active_checkbox;
        Engine::UI::ImGui::Element::InputField name_input;
        Container::ComponentStore component_store;
        Renderer::ComponentRenderer component_renderer;
        Engine::UI::ImGui::Menu::ContextMenu context_menu;

        void handle_select(
            Editor::Core::Select::SelectType select_type);
    };
}

#include "Planar/Editor/UI/Window/InspectorWindow.tpp"
