#pragma once

#include "Planar/Editor/Core/Select/SelectType.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>
#include <memory>

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(GameObject, GameObject)

namespace Planar::Editor::Core::Select
{
    class SelectHandler
    {
    public:
        SelectHandler();

        SelectType get_select_type() const;
        std::string get_name() const;
        std::shared_ptr<Engine::GameObject::GameObject>
            get_game_object() const;

        void select_content(const std::string& new_name);
        void select_game_object(
            std::shared_ptr<Engine::GameObject::GameObject>
            new_game_object);

    private:
        SelectType select_type;

        std::string name;
        std::shared_ptr<Engine::GameObject::GameObject> game_object;
    };
}
