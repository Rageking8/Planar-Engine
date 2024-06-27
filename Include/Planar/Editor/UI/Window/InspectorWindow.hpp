#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"
#include "Planar/Editor/UI/Element/Transform2D.hpp"
#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"
#include "Planar/Engine/UI/ImGui/Element/InputField.hpp"

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

    private:
        Engine::UI::ImGui::Element::InputField name_input;
        Element::Transform2D transform2d;

        void handle_select(Core::Select::SelectType select_type);
    };
}
