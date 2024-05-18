#include "Planar/Editor/UI/Window/SettingsWindow.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"

namespace Planar::Editor::UI::Window
{
    SettingsWindow::SettingsWindow() :
        pending_restore_default_layout{}
    {
        set("Settings");
    }

    void SettingsWindow::render_window()
    {
        using namespace Planar::Engine::UI;

        std::unique_ptr<Window::Scope> result = render();

        if (!result)
        {
            return;
        }

        if (ImGui::button("Restore Default Layout"))
        {
            pending_restore_default_layout = true;
        }
    }

    bool SettingsWindow::get_pending_restore_default_layout(bool reset)
    {
        bool result = pending_restore_default_layout;

        pending_restore_default_layout = result ? false :
            pending_restore_default_layout;

        return result;
    }
}
