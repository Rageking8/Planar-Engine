#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"

namespace Planar::Editor::UI::Window
{
    class SettingsWindow : public EditorWindow
    {
    public:
        SettingsWindow();

        virtual void render_window() override;

        bool get_pending_restore_default_layout(bool reset = true);

    private:
        bool pending_restore_default_layout;
    };
}
