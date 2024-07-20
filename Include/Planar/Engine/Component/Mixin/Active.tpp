#include "Planar/Engine/Component/Mixin/Active.hpp"

namespace Planar::Engine::Component::Mixin
{
    template <typename AssetT>
    inline Active<AssetT>::Active(AssetT* asset) :
        Engine::Core::Mixin::Mixin<AssetT>(asset), active{ true }
    {

    }

    template <typename AssetT>
    inline void Active<AssetT>::load()
    {
        set_active(this->asset->get_active());
    }

    template <typename AssetT>
    inline bool Active<AssetT>::get_active() const
    {
        return active;
    }

    template <typename AssetT>
    inline void Active<AssetT>::set_active(bool new_active)
    {
        active = new_active;
        this->asset->set_active(new_active);
    }
}
