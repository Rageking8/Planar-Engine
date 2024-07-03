#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Asset/Asset.hpp"

namespace Planar::Engine::Asset::Component::Mixin
{
    class PLANAR_API Mixin
    {
    public:
        Mixin(Asset* asset);

    protected:
        Asset* asset;
    };
}
