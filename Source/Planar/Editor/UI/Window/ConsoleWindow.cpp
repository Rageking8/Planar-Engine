#include "Planar/Editor/UI/Window/ConsoleWindow.hpp"

namespace Planar::Editor::UI::Window
{
    ConsoleWindow::ConsoleWindow()
    {
        set_name("Console");
    }

    void ConsoleWindow::render_window()
    {
        using namespace Planar::Engine::UI;

        std::unique_ptr<ImGuiWindow::Scope> result = render();

        if (!result)
        {
            return;
        }
    }
}
