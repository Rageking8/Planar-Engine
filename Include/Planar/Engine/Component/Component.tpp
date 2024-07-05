#include "Planar/Engine/Component/Component.hpp"

namespace Planar::Engine::Component
{
    template <typename ComponentT, typename AssetT>
    void Component<ComponentT, AssetT>::load(YAML::Node node)
    {
        asset.set_node(node);
        set_guid(asset.get_guid());

        load_impl(node);
    }

    template <typename ComponentT, typename AssetT>
    void Component<ComponentT, AssetT>::load_asset()
    {
        asset.load(*static_cast<ComponentT*>(this));
    }

    template <typename ComponentT, typename AssetT>
    const AssetT& Component<ComponentT, AssetT>::get_asset() const
    {
        return asset;
    }
}
