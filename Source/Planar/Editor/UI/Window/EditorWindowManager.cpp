#include "Planar/Editor/UI/Window/EditorWindowManager.hpp"

namespace Planar::Editor::UI::Window
{
    EditorWindowManager::EditorWindowManager(Core::Editor* editor) :
        editor{ editor }
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
