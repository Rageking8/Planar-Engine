#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"
#include "Planar/Engine/UI/ImGui/Element/InputField.hpp"

#include <string>

namespace Planar::Editor::UI::Window
{
    class InspectorWindow : public EditorWindow
    {
    public:
        InspectorWindow();

        virtual void render_window() override;

        void select_callback(const std::string& name);

    private:
        Engine::UI::ImGui::Element::InputField name_input;
    };
}
