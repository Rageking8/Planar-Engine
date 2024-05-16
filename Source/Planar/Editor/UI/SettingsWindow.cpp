#include "Planar/Editor/UI/SettingsWindow.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"

namespace Planar::Editor::UI
{
    SettingsWindow::SettingsWindow() :
        ImGuiWindow("Settings"), pending_restore_default_layout{}
    {

    }

    void SettingsWindow::render_window()
    {
        using namespace Planar::Engine::UI;

        std::unique_ptr<ImGuiWindow::Scope> result = render();

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
