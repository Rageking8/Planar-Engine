#include "Planar/Editor/UI/Window/Core/EditorWindowManager.hpp"
#include "Planar/Engine/Core/Utils/Checks/Assert.hpp"

namespace Planar::Editor::UI::Window::Core
{
    template <typename T>
        requires std::derived_from<T, EditorWindow>
    inline void EditorWindowManager::create(const std::string& name)
    {
        window_map[name] = std::make_shared<T>(editor);
    }

    template <typename T>
        requires std::derived_from<T, EditorWindow>
    inline std::shared_ptr<T> EditorWindowManager::get(
        const std::string& name)
    {
        PLANAR_ASSERT_CONTAINS(window_map, name);

        return std::static_pointer_cast<T>(window_map[name]);
    }
}
