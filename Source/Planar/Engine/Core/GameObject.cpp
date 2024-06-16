#include "Planar/Engine/Core/GameObject.hpp"

namespace Planar::Engine::Core
{
    GameObject::GameObject(const std::string& name) :
        name{ name }
    {

    }

    std::string GameObject::get_name() const
    {
        return name;
    }

    void GameObject::set_name(const std::string& new_name)
    {
        name = new_name;
    }
}
