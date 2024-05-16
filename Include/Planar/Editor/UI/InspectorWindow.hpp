#pragma once

#include "Planar/Engine/UI/ImGui/ImGuiWindow.hpp"

namespace Planar::Editor::UI
{
    class InspectorWindow :
        public Planar::Engine::UI::ImGui::ImGuiWindow
    {
    public:
        InspectorWindow();

        void render_window();
    };
}
