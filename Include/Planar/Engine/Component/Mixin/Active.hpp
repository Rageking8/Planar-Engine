#pragma once

#include "Planar/Engine/Core/Mixin/Mixin.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

PLANAR_FORWARD_DECLARE_CLASS(YAML, Node)

namespace Planar::Engine::Component::Mixin
{
    template <typename AssetT>
    class Active : public Engine::Core::Mixin::Mixin<AssetT>
    {
    public:
        using Engine::Core::Mixin::Mixin<AssetT>::Mixin;

        void load(YAML::Node node);

        bool get_active() const;
        void set_active(bool new_active);

    private:
        bool active;
    };
}

#include "Planar/Engine/Component/Mixin/Active.tpp"
