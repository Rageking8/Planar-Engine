#pragma once

#include "Planar/Editor/UI/Window/Core/EditorWindow.hpp"
#include "Planar/Engine/UI/ImGui/Element/InputField.hpp"
#include "Planar/Engine/UI/ImGui/Element/DropDown.hpp"
#include "Planar/Engine/UI/ImGui/Element/Button/Button.hpp"
#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"

PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Core, Editor)

namespace Planar::Editor::UI::Window
{
    class CreateScriptWindow : public Core::EditorWindow
    {
    public:
        CreateScriptWindow(Editor::Core::Editor* editor);

        virtual void update() override;

        virtual void render_window() override;

    private:
        Engine::UI::ImGui::Element::InputField script_name_input;
        Engine::UI::ImGui::Element::DropDown script_type_dropdown;
        Engine::UI::ImGui::Element::Button::Button create_button;

        bool pending_create;

        void create();
    };
}
