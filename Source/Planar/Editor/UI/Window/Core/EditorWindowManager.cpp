#include "Planar/Editor/UI/Window/Core/EditorWindowManager.hpp"
#include "Planar/Engine/Core/Utils/Checks/Assert.hpp"

namespace Planar::Editor::UI::Window::Core
{
    EditorWindowManager::EditorWindowManager(
        Editor::Core::Editor* editor) : editor{ editor }
    {

    }

    std::shared_ptr<EditorWindow> EditorWindowManager::get(
        const std::string& name) const
    {
        PLANAR_ASSERT_CONTAINS(window_map, name);

        return window_map.at(name);
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
