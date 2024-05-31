#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"
#include "Planar/Engine/UI/ImGui/Element/InputField.hpp"

namespace Planar::Editor::UI::Window
{
    class InspectorWindow : public EditorWindow
    {
    public:
        InspectorWindow();

        virtual void render_window() override;

    private:
        Engine::UI::ImGui::Element::InputField name_input;
    };
}
