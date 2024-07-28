#include "Planar/Engine/Component/Core/Component.hpp"
#include "Planar/Engine/Component/Mixin/Active.hpp"

#include <type_traits>

#define PLANAR_DEFINE_COMPONENT_CALLBACK(name)                   \
    template <typename ComponentT, typename AssetT,              \
        template <typename> typename... Mixins>                  \
    inline void Component<ComponentT, AssetT, Mixins...>::name() \
    {                                                            \
        if (skip_callback())                                     \
        {                                                        \
            return;                                              \
        }                                                        \
                                                                 \
        name##_impl();                                           \
    }                                                            \

#define PLANAR_DEFINE_COMPONENT_EMPTY_CALLBACK_IMPL(name)               \
    template <typename ComponentT, typename AssetT,                     \
        template <typename> typename... Mixins>                         \
    inline void Component<ComponentT, AssetT, Mixins...>::name##_impl() \
    {                                                                   \
                                                                        \
    }                                                                   \

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
        // (Mixins<AssetT>::load(), ...);
        auto x = { 0, (Mixins<AssetT>::load(), 0)... };

        load_impl();
    }

    PLANAR_DEFINE_COMPONENT_CALLBACK(update)
    PLANAR_DEFINE_COMPONENT_CALLBACK(late_update)
    PLANAR_DEFINE_COMPONENT_CALLBACK(render)
    PLANAR_DEFINE_COMPONENT_CALLBACK(application_quit)

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

    PLANAR_DEFINE_COMPONENT_EMPTY_CALLBACK_IMPL(update)
    PLANAR_DEFINE_COMPONENT_EMPTY_CALLBACK_IMPL(late_update)
    PLANAR_DEFINE_COMPONENT_EMPTY_CALLBACK_IMPL(render)
    PLANAR_DEFINE_COMPONENT_EMPTY_CALLBACK_IMPL(application_quit)

    template <typename ComponentT, typename AssetT,
        template <typename> typename... Mixins>
    inline bool Component<ComponentT, AssetT, Mixins...>::
        skip_callback() const
    {
        if constexpr ((std::is_same_v<Mixin::Active<AssetT>,
            Mixins<AssetT>> || ...))
        {
            if (!Mixin::Active<AssetT>::get_active())
            {
                return true;
            }
        }

        return false;
    }
}

#undef PLANAR_DEFINE_COMPONENT_CALLBACK
#undef PLANAR_DEFINE_COMPONENT_EMPTY_CALLBACK_IMPL
