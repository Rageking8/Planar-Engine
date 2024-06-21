#pragma once

#include "Planar/Editor/Core/Editor.hpp"
#include "Planar/Engine/UI/ImGui/Window/Window.hpp"

#include <string>

namespace Planar::Editor::UI::Window
{
    class EditorWindow :
        public Engine::UI::ImGui::Window::Window
    {
    public:
        EditorWindow(const std::string& name,
            Core::Editor* editor, bool active = true);

        virtual void render_window() = 0;

    protected:
        Core::Editor* editor;
    };
}
