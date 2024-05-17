#pragma once

#include "Planar/Engine/UI/ImGui/Window/ImGuiWindow.hpp"

namespace Planar::Editor::UI::Window
{
    class GameWindow :
        public Planar::Engine::UI::ImGui::Window::ImGuiWindow
    {
    public:
        GameWindow();

        void render_window();
    };
}
