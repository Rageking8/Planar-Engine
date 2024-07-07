#pragma once

#include "Planar/Engine/Core/Mixin/Mixin.hpp"
#include "Planar/Engine/Asset/Asset.hpp"

namespace Planar::Engine::Asset::Component::Mixin
{
    template <typename ComponentT>
    class Active : public Engine::Core::Mixin::Mixin<Asset>
    {
    public:
        bool get_active() const;
        void set_active(bool new_active);

        void load(ComponentT& component);
    };
}

#include "Planar/Engine/Asset/Component/Mixin/Active.tpp"
