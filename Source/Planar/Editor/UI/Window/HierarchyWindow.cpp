#include "Planar/Editor/UI/Window/HierarchyWindow.hpp"

namespace Planar::Editor::UI::Window
{
    HierarchyWindow::HierarchyWindow() : EditorWindow("Hierarchy")
    {
        set_padding({ { 0.f, 15.f } });
    }

    void HierarchyWindow::render_window()
    {
        using namespace Engine::UI;

        std::unique_ptr<Window::Scope> result = render();

        if (!result)
        {
            return;
        }

        if (editor && editor->get_current_scene())
        {
            current_scene_tree.set_label(
                editor->get_current_scene()->get_asset().get_name());
            current_scene_tree.render();
        }
    }
}
