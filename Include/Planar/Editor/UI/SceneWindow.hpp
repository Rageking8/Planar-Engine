#pragma once

#include "Planar/Engine/UI/ImGui/Window/ImGuiWindow.hpp"

namespace Planar::Editor::UI
{
    class SceneWindow :
        public Planar::Engine::UI::ImGui::Window::ImGuiWindow
    {
    public:
        SceneWindow();

        void render_window();
    };
}
