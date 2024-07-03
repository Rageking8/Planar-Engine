#pragma once

#include "Planar/Engine/Asset/Component/Mixin/Mixin.hpp"

namespace Planar::Engine::Asset::Component::Mixin
{
    template <typename ComponentT>
    class Active : public Mixin
    {
    public:
        bool get_active() const;
        void set_active(bool new_active);

        void load(ComponentT& component);
    };
}

#include "Planar/Engine/Asset/Component/Mixin/Active.tpp"
