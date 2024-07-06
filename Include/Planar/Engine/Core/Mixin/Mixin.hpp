#pragma once

namespace Planar::Engine::Core::Mixin
{
    template <typename AssetT>
    class Mixin
    {
    public:
        Mixin(AssetT* asset);

    protected:
        AssetT* asset;
    };
}

#include "Planar/Engine/Core/Mixin/Mixin.tpp"
