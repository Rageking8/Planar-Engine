#pragma once

#include "Planar/Engine/Core/GameObject.hpp"

#include <string>
#include <functional>

namespace Planar::Editor::Core::Select
{
    class SelectHandler
    {
    public:
        using ContentCallback = std::function<void(const std::string&)>;
        using GameObjectCallback =
            std::function<void(const Engine::Core::GameObject&)>;

        SelectHandler();

        void select_content(const std::string& name);
        void select_game_object(
            const Engine::Core::GameObject& game_object);

        void set_content_callback(
            const ContentCallback& new_content_callback);
        void set_game_object_callback(
            const GameObjectCallback& new_game_object_callback);

    private:
        ContentCallback content_callback;
        GameObjectCallback game_object_callback;
    };
}
