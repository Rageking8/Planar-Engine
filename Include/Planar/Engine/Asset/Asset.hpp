#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

namespace Planar::Engine::Asset
{
    class PLANAR_API Asset
    {
    public:
        Asset();
        virtual ~Asset() = 0;
    };
}
