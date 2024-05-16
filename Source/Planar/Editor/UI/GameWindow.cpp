#include "Planar/Editor/UI/GameWindow.hpp"

namespace Planar::Editor::UI
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
