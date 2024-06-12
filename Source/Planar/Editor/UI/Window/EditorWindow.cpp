#include "Planar/Editor/UI/Window/EditorWindow.hpp"

namespace Planar::Editor::UI::Window
{
    EditorWindow::EditorWindow(const std::string& name,
        bool active) : Window(name, {}, active), editor{}
    {

    }

    void EditorWindow::set_editor(Core::Editor* new_editor)
    {
        editor = new_editor;
    }
}
