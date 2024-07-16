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
        SelectHandler::get_game_object()
    {
        std::shared_ptr<Engine::GameObject::GameObject> result =
            game_object.lock();

        if (!result)
        {
            select_type = SelectType::NONE;
            game_object.reset();
        }

        return result;
    }

    void SelectHandler::select_none(SelectType if_select_type)
    {
        if (select_type != if_select_type)
        {
            return;
        }

        select_type = SelectType::NONE;

        invoke_select_callback();
    }

    void SelectHandler::select_content(const std::string& new_name)
    {
        select_type = SelectType::CONTENT;
        name = new_name;

        invoke_select_callback();
    }

    void SelectHandler::select_game_object(
        std::weak_ptr<Engine::GameObject::GameObject> new_game_object,
        const std::string& restore_guid)
    {
        select_type = SelectType::GAME_OBJECT;
        game_object = new_game_object;
        game_object_restore_guid = restore_guid;

        invoke_select_callback();
    }

    void SelectHandler::restore_game_object(
        std::shared_ptr<Engine::GameObject::GameObject> root)
    {
        if (select_type != SelectType::GAME_OBJECT)
        {
            return;
        }

        std::shared_ptr<Engine::GameObject::GameObject> result =
            root->find_game_object(game_object_restore_guid);

        if (result)
        {
            select_game_object(result, result->get_guid());
        }
    }

    void SelectHandler::invoke_select_callback()
    {
        if (select_callback)
        {
            select_callback(select_type);
        }
    }
}
