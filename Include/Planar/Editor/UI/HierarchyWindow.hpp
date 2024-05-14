#pragma once

#include "Planar/Engine/UI/ImGui/ImGuiWindow.hpp"

namespace Planar::Editor::UI
{
    class HierarchyWindow :
        public Planar::Engine::UI::ImGui::ImGuiWindow
    {
    public:
        HierarchyWindow();

        void render_window();
    };
}
