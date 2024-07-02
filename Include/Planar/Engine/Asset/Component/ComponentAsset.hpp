#pragma once

#include "Planar/Engine/Asset/Asset.hpp"

#include <string>

namespace Planar::Engine::Asset::Component
{
    template <typename ComponentT>
    class ComponentAsset : public Asset
    {
    public:
        ComponentAsset();

        void load(ComponentT& component);

        std::string get_guid() const;

    private:
        virtual void load_impl(ComponentT& component) = 0;
    };
}

#include "Planar/Engine/Asset/Component/ComponentAsset.tpp"
