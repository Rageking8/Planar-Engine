#include "Planar/Editor/Core/Select/SelectHandler.hpp"
#include "Planar/Engine/GameObject/GameObject.hpp"

namespace Planar::Editor::Core::Select
{
    SelectHandler::SelectHandler() : select_type{ SelectType::NONE }
    {

    }

    void SelectHandler::set_select_callback(
        const SelectCallback& new_select_callback)
    {
        select_callback = new_select_callback;
    }

    SelectType SelectHandler::get_select_type() const
    {
        return select_type;
    }

    std::string SelectHandler::get_name() const
    {
        return name;
    }

    std::shared_ptr<Engine::GameObject::GameObject>
        SelectHandler::get_game_object() const
    {
        return game_object;
    }

    void SelectHandler::select_content(const std::string& new_name)
    {
        select_type = SelectType::CONTENT;
        name = new_name;

        invoke_select_callback();
    }

    void SelectHandler::select_game_object(
        std::shared_ptr<Engine::GameObject::GameObject> new_game_object)
    {
        select_type = SelectType::GAME_OBJECT;
        game_object = new_game_object;

        invoke_select_callback();
    }

    void SelectHandler::invoke_select_callback()
    {
        if (select_callback)
        {
            select_callback(select_type);
        }
    }
}
