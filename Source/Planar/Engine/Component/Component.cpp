#include "Planar/Engine/Component/Component.hpp"

namespace Planar::Engine::Core::Component
{
    Component::Component() : active{ true }
    {

    }

    bool Component::get_active() const
    {
        return active;
    }

    void Component::set_active(bool new_active)
    {
        active = new_active;
    }
}
