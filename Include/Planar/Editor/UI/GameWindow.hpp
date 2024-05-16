#pragma once

#include "Planar/Engine/UI/ImGui/ImGuiWindow.hpp"

namespace Planar::Editor::UI
{
    class GameWindow :
        public Planar::Engine::UI::ImGui::ImGuiWindow
    {
    public:
        GameWindow();

        void render_window();
    };
}
