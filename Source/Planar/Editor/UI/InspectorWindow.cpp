#include "Planar/Editor/UI/InspectorWindow.hpp"

namespace Planar::Editor::UI
{
    InspectorWindow::InspectorWindow() :
        ImGuiWindow("Inspector")
    {

    }

    void InspectorWindow::render_window()
    {
        using namespace Planar::Engine::UI;

        std::unique_ptr<ImGuiWindow::Scope> result = render();

        if (!result)
        {
            return;
        }
    }
}
