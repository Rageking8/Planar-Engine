#include "Planar/Editor/UI/Window/EditorWindow.hpp"

namespace Planar::Editor::UI::Window
{
    EditorWindow::EditorWindow(const std::string& name,
        Core::Editor* editor, bool active) :
        Window(name, {}, active), editor{ editor }
    {

    }
}
