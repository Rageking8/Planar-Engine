#include "Planar/Editor/UI/Window/SceneWindow.hpp"

namespace Planar::Editor::UI::Window
{
    SceneWindow::SceneWindow()
    {
        set("Scene");
    }

    void SceneWindow::render_window()
    {
        using namespace Planar::Engine::UI;

        std::unique_ptr<ImGuiWindow::Scope> result = render();

        if (!result)
        {
            return;
        }
    }
}