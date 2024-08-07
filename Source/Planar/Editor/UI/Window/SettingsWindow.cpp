#include "Planar/Editor/UI/Window/SettingsWindow.hpp"

namespace Planar::Editor::UI::Window
{
    SettingsWindow::SettingsWindow(Editor::Core::Editor* editor) :
        EditorWindow("Settings", editor),
        pending_restore_default_layout{},
        restore_default_layout_button("Restore Default Layout")
    {

    }

    void SettingsWindow::render_window()
    {
        using namespace Planar::Engine::UI;

        std::unique_ptr<Window::Scope> result = render();

        if (!result)
        {
            return;
        }

        restore_default_layout_button.render();
        if (restore_default_layout_button.is_clicked())
        {
            pending_restore_default_layout = true;
        }
    }

    bool SettingsWindow::get_pending_restore_default_layout(bool reset)
    {
        bool result = pending_restore_default_layout;

        pending_restore_default_layout = reset ? false :
            pending_restore_default_layout;

        return result;
    }
}
