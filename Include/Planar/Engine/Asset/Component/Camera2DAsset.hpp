#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Asset/Asset.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Component, Camera2D)

namespace Planar::Engine::Asset::Component
{
    class PLANAR_API Camera2DAsset : public Asset
    {
    public:
        Camera2DAsset();

        void load(Engine::Component::Camera2D& camera);

        std::string get_guid() const;
    };
}
