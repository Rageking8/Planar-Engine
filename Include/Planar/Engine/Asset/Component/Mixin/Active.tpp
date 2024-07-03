#include "Planar/Engine/Asset/Component/Mixin/Active.hpp"

namespace Planar::Engine::Asset::Component::Mixin
{
    template <typename ComponentT>
    bool Active<ComponentT>::get_active() const
    {
        return asset->get_value<bool>("Active");
    }

    template <typename ComponentT>
    void Active<ComponentT>::set_active(bool new_active)
    {
        asset->set_value("Active", new_active);
    }

    template <typename ComponentT>
    void Active<ComponentT>::load(ComponentT& component)
    {
        asset->set_value("Active", component.get_active());
    }
}
