#include "Planar/Editor/UI/Window/SceneWindow.hpp"

namespace Planar::Editor::UI::Window
{
    SceneWindow::SceneWindow(Core::Editor* editor) :
        EditorWindow("Scene", editor)
    {

    }

    void SceneWindow::render_window()
    {
        using namespace Planar::Engine::UI;

        std::unique_ptr<Window::Scope> result = render();

        if (!result)
        {
            return;
        }
    }
}
