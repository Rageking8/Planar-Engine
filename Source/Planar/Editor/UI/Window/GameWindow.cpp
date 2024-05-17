#include "Planar/Editor/UI/Window/GameWindow.hpp"

namespace Planar::Editor::UI::Window
{
    GameWindow::GameWindow() :
        ImGuiWindow("Game")
    {

    }

    void GameWindow::render_window()
    {
        using namespace Planar::Engine::UI;

        std::unique_ptr<ImGuiWindow::Scope> result = render();

        if (!result)
        {
            return;
        }
    }
}
