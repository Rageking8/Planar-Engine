#include "Planar/Editor/UI/ConsoleWindow.hpp"

namespace Planar::Editor::UI
{
    ConsoleWindow::ConsoleWindow() :
        ImGuiWindow("Console")
    {

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
