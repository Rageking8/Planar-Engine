#pragma once

#include "Planar/Engine/Asset/Asset.hpp"

#include <string>

namespace Planar::Engine::Asset::Component::Core
{
    template <typename ComponentT,
        template <typename> typename... Mixins>
    class ComponentAsset : public Asset, public Mixins<ComponentT>...
    {
    public:
        ComponentAsset();

        void load(ComponentT& component);

        std::string get_guid() const;

    private:
        virtual void load_impl(ComponentT& component) = 0;
    };
}

#include "Planar/Engine/Asset/Component/Core/ComponentAsset.tpp"
