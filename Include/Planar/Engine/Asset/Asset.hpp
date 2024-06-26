#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

namespace Planar::Engine::Asset
{
    class PLANAR_API Asset
    {
    public:
        Asset();
        virtual ~Asset() = 0;

        YAML::Node get_asset() const;

    protected:
        YAML::Node asset;
    };
}
