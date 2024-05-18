#pragma once

#include "Planar/Engine/UI/ImGui/Window/Window.hpp"

namespace Planar::Editor::UI::Window
{
    class EditorWindow :
        public Planar::Engine::UI::ImGui::Window::Window
    {
    public:
        virtual void render_window() = 0;
    };
}
