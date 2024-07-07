#pragma once

#include "Planar/Engine/Core/Mixin/Mixin.hpp"

namespace Planar::Engine::Component::Mixin
{
    template <typename AssetT>
    class Active : public Engine::Core::Mixin::Mixin<AssetT>
    {
    public:
        using Engine::Core::Mixin::Mixin<AssetT>::Mixin;

        void load();

        bool get_active() const;
        void set_active(bool new_active);

    private:
        bool active;
    };
}

#include "Planar/Engine/Component/Mixin/Active.tpp"
