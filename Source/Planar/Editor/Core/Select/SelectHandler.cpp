#include "Planar/Editor/Core/Select/SelectHandler.hpp"

namespace Planar::Editor::Core::Select
{
    SelectHandler::SelectHandler()
    {

    }

    void SelectHandler::select_content(const std::string& name)
    {
        content_callback(name);
    }

    void SelectHandler::select_game_object(
        const Engine::Core::GameObject& game_object)
    {
        game_object_callback(game_object);
    }

    void SelectHandler::set_content_callback(
        const ContentCallback& new_content_callback)
    {
        content_callback = new_content_callback;
    }

    void SelectHandler::set_game_object_callback(
        const GameObjectCallback& new_game_object_callback)
    {
        game_object_callback = new_game_object_callback;
    }
}
