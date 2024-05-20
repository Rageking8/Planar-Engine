#pragma once

#include "Planar/Editor/UI/Window/EditorWindow.hpp"
#include "Planar/Engine/UI/ImGui/Element/Button.hpp"

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

        Planar::Engine::UI::ImGui::Element::Button
            restore_default_layout_button;
    };
}
