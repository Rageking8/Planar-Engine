#include "Planar/Engine/Asset/Component/ComponentAsset.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

namespace Planar::Engine::Asset::Component
{
    template <typename ComponentT>
    inline ComponentAsset<ComponentT>::ComponentAsset()
    {

    }

    template <typename ComponentT>
    inline void ComponentAsset<ComponentT>::load(
        ComponentT& component)
    {
        get("Type") = component.NAME;
        get("GUID") = component.get_guid();

        load_impl(component);
    }

    template <typename ComponentT>
    inline std::string ComponentAsset<ComponentT>::get_guid() const
    {
        return get_scalar("GUID");
    }
}
