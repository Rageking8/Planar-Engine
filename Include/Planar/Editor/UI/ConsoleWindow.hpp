#pragma once

#include "Planar/Engine/UI/ImGui/ImGuiWindow.hpp"

namespace Planar::Editor::UI
{
    class ConsoleWindow :
        public Planar::Engine::UI::ImGui::ImGuiWindow
    {
    public:
        ConsoleWindow();

        void render_window();
    };
}
