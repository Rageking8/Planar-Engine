#include "Planar/Editor/UI/Window/Core/EditorWindowManager.hpp"

namespace Planar::Editor::UI::Window::Core
{
    EditorWindowManager::EditorWindowManager(
        Editor::Core::Editor* editor) : editor{ editor }
    {

    }

    void EditorWindowManager::init()
    {
        for (const auto& i : window_map)
        {
            i.second->init();
        }
    }

    void EditorWindowManager::update()
    {
        for (const auto& i : window_map)
        {
            i.second->update();
        }
    }

    void EditorWindowManager::render()
    {
        for (const auto& i : window_map)
        {
            i.second->render_window();
        }
    }
}
