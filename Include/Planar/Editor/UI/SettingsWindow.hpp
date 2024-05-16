#pragma once

#include "Planar/Engine/UI/ImGui/ImGuiWindow.hpp"

namespace Planar::Editor::UI
{
    class SettingsWindow :
        public Planar::Engine::UI::ImGui::ImGuiWindow
    {
    public:
        SettingsWindow();

        void render_window();

        bool get_pending_restore_default_layout(bool reset = true);

    private:
        bool pending_restore_default_layout;
    };
}
