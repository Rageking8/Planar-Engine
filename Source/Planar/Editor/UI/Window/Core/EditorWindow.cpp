#include "Planar/Editor/UI/Window/Core/EditorWindow.hpp"

namespace Planar::Editor::UI::Window::Core
{
    EditorWindow::EditorWindow(const std::string& name,
        Editor::Core::Editor* editor, bool active) :
        Window(name, {}, active), editor{ editor }
    {

    }

    void EditorWindow::init()
    {

    }

    void EditorWindow::update()
    {

    }
}
