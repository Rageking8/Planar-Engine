#include "Planar/Editor/UI/Window/HierarchyWindow.hpp"

namespace Planar::Editor::UI::Window
{
    HierarchyWindow::HierarchyWindow() :
        ImGuiWindow("Hierarchy")
    {

    }

    void HierarchyWindow::render_window()
    {
        using namespace Planar::Engine::UI;

        std::unique_ptr<ImGuiWindow::Scope> result = render();

        if (!result)
        {
            return;
        }
    }
}
