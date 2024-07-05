#include "Planar/Editor/UI/Window/InspectorWindow.hpp"
#include "Planar/Editor/Core/Editor.hpp"
#include "Planar/Editor/Core/Select/SelectHandler.hpp"

namespace Planar::Editor::UI::Window
{
    template <typename ComponentT>
    inline void InspectorWindow::add_component()
    {
        Core::Select::SelectHandler& select_handler =
            editor->get_select_handler();
        const Core::Select::SelectType select_type =
            select_handler.get_select_type();

        if (select_type != Core::Select::SelectType::GAME_OBJECT)
        {
            return;
        }

        std::shared_ptr<Engine::GameObject::GameObject>
            game_object = select_handler.get_game_object();

        if (!game_object)
        {
            return;
        }

        game_object->add_component<ComponentT>();
        component_store.update_items(*game_object);
        editor->set_dirty();
    }
}
