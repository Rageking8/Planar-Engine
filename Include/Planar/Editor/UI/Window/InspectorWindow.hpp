#pragma once

#include "Planar/Engine/UI/ImGui/Window/ImGuiWindow.hpp"

namespace Planar::Editor::UI::Window
{
    class InspectorWindow :
        public Planar::Engine::UI::ImGui::Window::ImGuiWindow
    {
    public:
        InspectorWindow();

        void render_window();
    };
}
