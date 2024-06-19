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

        void init();

        virtual void render_window() override;

    private:
        Engine::UI::ImGui::Element::InputField name_input;

        void select_content(const std::string& name);
    };
}
