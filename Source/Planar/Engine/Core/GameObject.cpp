#include "Planar/Engine/Core/GameObject.hpp"
#include "Planar/Engine/Core/GUID/GUID.hpp"

namespace Planar::Engine::Core
{
    GameObject::GameObject(const std::string& name) :
        name{ name }
    {
        guid = GUID::generate_guid(
            GUID::Representation::DEFAULT_COMPACT);
    }

    GameObject::GameObject(const std::string& name,
        const std::string& guid) : name{ name }, guid{ guid }
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

    std::string GameObject::get_guid() const
    {
        return guid;
    }
}
