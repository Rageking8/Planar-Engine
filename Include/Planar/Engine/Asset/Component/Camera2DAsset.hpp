#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Asset/Component/Core/ComponentAsset.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"
#include "Planar/Engine/Asset/Component/Mixin/Active.hpp"

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Component, Camera2D)

namespace Planar::Engine::Asset::Component
{
    class PLANAR_API Camera2DAsset :
        public Core::ComponentAsset<Engine::Component::Camera2D,
        Mixin::Active>
    {
    public:
        Camera2DAsset();

        PLANAR_DECLARE_GET_SET(float, pixel_scale)

    private:
        virtual void load_impl(
            Engine::Component::Camera2D& camera) override;
    };
}
