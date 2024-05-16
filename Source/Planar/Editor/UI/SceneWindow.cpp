#include "Planar/Editor/UI/SceneWindow.hpp"

namespace Planar::Editor::UI
{
    SceneWindow::SceneWindow() :
        ImGuiWindow("Scene")
    {

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
