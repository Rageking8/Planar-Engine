#pragma once

#include "Planar/Engine/UI/ImGui/ImGuiWindow.hpp"

namespace Planar::Editor::UI
{
    class SceneWindow :
        public Planar::Engine::UI::ImGui::ImGuiWindow
    {
    public:
        SceneWindow();

        void render_window();
    };
}
