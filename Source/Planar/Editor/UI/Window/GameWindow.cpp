#include "Planar/Editor/UI/Window/GameWindow.hpp"

namespace Planar::Editor::UI::Window
{
    GameWindow::GameWindow()
    {
        set("Game");
    }

    void GameWindow::render_window()
    {
        using namespace Planar::Engine::UI;

        std::unique_ptr<Window::Scope> result = render();

        if (!result)
        {
            return;
        }
    }
}
