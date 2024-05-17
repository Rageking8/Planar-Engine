#pragma once

#include "Planar/Engine/UI/ImGui/Window/ImGuiWindow.hpp"

namespace Planar::Editor::UI::Window
{
    class EditorWindow :
        public Planar::Engine::UI::ImGui::Window::ImGuiWindow
    {
    public:
        virtual void render_window() = 0;
    };
}
