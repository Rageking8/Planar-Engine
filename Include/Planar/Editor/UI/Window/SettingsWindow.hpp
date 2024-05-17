#pragma once

#include "Planar/Engine/UI/ImGui/Window/ImGuiWindow.hpp"

namespace Planar::Editor::UI::Window
{
    class SettingsWindow :
        public Planar::Engine::UI::ImGui::Window::ImGuiWindow
    {
    public:
        SettingsWindow();

        void render_window();

        bool get_pending_restore_default_layout(bool reset = true);

    private:
        bool pending_restore_default_layout;
    };
}
