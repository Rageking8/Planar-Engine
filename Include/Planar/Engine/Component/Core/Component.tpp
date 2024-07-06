#include "Planar/Engine/Component/Core/Component.hpp"

namespace Planar::Engine::Component::Core
{
    template <typename ComponentT, typename AssetT,
        template <typename> typename... Mixins>
    inline Component<ComponentT, AssetT, Mixins...>::Component(
        GameObject::GameObject* parent, bool generate_guid) :
        ComponentBase(parent, generate_guid), Mixins<AssetT>(&asset)...
    {

    }

    template <typename ComponentT, typename AssetT,
        template <typename> typename... Mixins>
    inline void Component<ComponentT, AssetT, Mixins...>::load(
        YAML::Node node)
    {
        asset.set_node(node);
        set_guid(asset.get_guid());

        // WORKAROUND: Due to a MSVC bug, the following fold
        // expression does nothing instead of invoking `load`
        // for all mixins
        // (Mixins<AssetT>::load(node), ...);
        auto x = { 0, (Mixins<AssetT>::load(node), 0)... };

        load_impl(node);
    }

    template <typename ComponentT, typename AssetT,
        template <typename> typename... Mixins>
    inline void Component<ComponentT, AssetT, Mixins...>::load_asset()
    {
        asset.load(*static_cast<ComponentT*>(this));
    }

    template <typename ComponentT, typename AssetT,
        template <typename> typename... Mixins>
    inline const AssetT& Component<ComponentT, AssetT, Mixins...>::
        get_asset() const
    {
        return asset;
    }
}
