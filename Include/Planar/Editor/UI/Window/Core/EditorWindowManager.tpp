#include "Planar/Editor/UI/Window/Core/EditorWindowManager.hpp"

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
        return std::static_pointer_cast<T>(get(name));
    }
}
