#pragma once

#include "Planar/Engine/UI/ImGui/Window/Window.hpp"
#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>

PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Core, Editor)

namespace Planar::Editor::UI::Window::Core
{
    class EditorWindow :
        public Engine::UI::ImGui::Window::Window
    {
    public:
        EditorWindow(const std::string& name,
            Editor::Core::Editor* editor, bool active = true);

        virtual void init();
        virtual void update();

        virtual void render_window() = 0;

    protected:
        Editor::Core::Editor* editor;
    };
}
