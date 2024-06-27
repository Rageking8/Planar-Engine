#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <memory>

PLANAR_FORWARD_DECLARE_CLASS(YAML, Node)

namespace Planar::Engine::Asset
{
    class PLANAR_API Asset
    {
    public:
        Asset();
        virtual ~Asset() = 0;

        YAML::Node get_asset() const;

    protected:
        std::unique_ptr<YAML::Node> asset;
    };
}
