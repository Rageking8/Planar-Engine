#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"
#include "Planar/Engine/UI/ImGui/Element/InputField.hpp"
#include "Planar/Engine/GameObject/GameObject.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>

PLANAR_FORWARD_DECLARE_CLASS(Editor::Core, Editor)

namespace Planar::Editor::UI::Window
{
    class InspectorWindow : public EditorWindow
    {
    public:
        InspectorWindow(Core::Editor* editor);

        void init();

        virtual void render_window() override;

    private:
        Engine::UI::ImGui::Element::InputField name_input;

        void select_content(const std::string& name);
        void select_game_object(
            const Engine::GameObject::GameObject& game_object);
    };
}
