#include "Planar/Engine/Asset/Component/Core/ComponentAsset.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

namespace Planar::Engine::Asset::Component::Core
{
    template <typename ComponentT,
        template <typename> typename... Mixins>
    inline ComponentAsset<ComponentT, Mixins...>::ComponentAsset() :
        Mixins<ComponentT>(static_cast<Asset*>(this))...
    {

    }

    template <typename ComponentT,
        template <typename> typename... Mixins>
    inline void ComponentAsset<ComponentT, Mixins...>::load(
        ComponentT& component)
    {
        set_value("Type", component.NAME);
        set_value("GUID", component.get_guid());

        // WORKAROUND: Due to a MSVC bug, the following fold
        // expression does nothing instead of invoking `load`
        // for all mixins
        // (Mixins<ComponentT>::load(component), ...);
        auto x = { 0, (Mixins<ComponentT>::load(component), 0)... };

        load_impl(component);
    }

    template <typename ComponentT,
        template <typename> typename... Mixins>
    inline std::string ComponentAsset<ComponentT, Mixins...>::
        get_guid() const
    {
        return get_value<std::string>("GUID");
    }
}
