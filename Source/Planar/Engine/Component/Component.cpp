#include "Planar/Engine/Component/Component.hpp"
#include "Planar/Engine/Core/GUID/GUID.hpp"

namespace Planar::Engine::Component
{
    Component::Component(bool generate_guid) : active{ true }
    {
        if (generate_guid)
        {
            guid = Core::GUID::generate_guid(
                Core::GUID::Representation::DEFAULT_COMPACT);
        }
    }

    Component::~Component()
    {

    }

    bool Component::match(ComponentType other) const
    {
        return other == TYPE;
    }

    bool Component::get_active() const
    {
        return active;
    }

    void Component::set_active(bool new_active)
    {
        active = new_active;
    }

    std::string Component::get_guid() const
    {
        return guid;
    }

    void Component::set_guid(const std::string& new_guid)
    {
        guid = new_guid;
    }
}
