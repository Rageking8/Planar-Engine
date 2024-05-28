#include "Planar/Editor/UI/Window/InspectorWindow.hpp"

namespace Planar::Editor::UI::Window
{
    InspectorWindow::InspectorWindow() : EditorWindow("Inspector")
    {

    }

    void InspectorWindow::render_window()
    {
        using namespace Planar::Engine::UI;

        std::unique_ptr<Window::Scope> result = render();

        if (!result)
        {
            return;
        }
    }
}
