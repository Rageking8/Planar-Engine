#pragma once

#include "Planar/Engine/UI/ImGui/Window/ImGuiWindow.hpp"

namespace Planar::Editor::UI
{
    class HierarchyWindow :
        public Planar::Engine::UI::ImGui::Window::ImGuiWindow
    {
    public:
        HierarchyWindow();

        void render_window();
    };
}
