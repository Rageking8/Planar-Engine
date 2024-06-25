#include "Planar/Engine/GameObject/GameObject.hpp"
#include "Planar/Engine/Core/GUID/GUID.hpp"

namespace Planar::Engine::GameObject
{
    GameObject::GameObject(const std::string& name) :
        name{ name }
    {
        guid = Core::GUID::generate_guid(
            Core::GUID::Representation::DEFAULT_COMPACT);
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
