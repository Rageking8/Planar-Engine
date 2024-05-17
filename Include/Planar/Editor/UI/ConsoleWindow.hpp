#pragma once

#include "Planar/Engine/UI/ImGui/Window/ImGuiWindow.hpp"

namespace Planar::Editor::UI
{
    class ConsoleWindow :
        public Planar::Engine::UI::ImGui::Window::ImGuiWindow
    {
    public:
        ConsoleWindow();

        void render_window();
    };
}
