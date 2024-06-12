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
        EditorWindow(const std::string& name, bool active = true);

        virtual void render_window() = 0;

        void set_editor(Core::Editor* new_editor);

    protected:
        Core::Editor* editor;
    };
}
