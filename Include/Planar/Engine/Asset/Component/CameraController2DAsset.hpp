#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Math/Size2D.hpp"
#include "Planar/Engine/Asset/Component/Core/ComponentAsset.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"
#include "Planar/Engine/Asset/Component/Mixin/Active.hpp"

#include <string>

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Component, CameraController2D)

namespace Planar::Engine::Asset::Component
{
    class PLANAR_API CameraController2DAsset :
        public Core::ComponentAsset<
        Engine::Component::CameraController2D, Mixin::Active>
    {
    public:
        CameraController2DAsset();

        PLANAR_DECLARE_GET_SET(std::string, mode)
        PLANAR_DECLARE_GET_SET(Math::Size2Df, horizontal_speed)
        PLANAR_DECLARE_GET_SET(Math::Size2Df, vertical_speed)
        PLANAR_DECLARE_GET_SET(std::string, tracked_transform)
        PLANAR_DECLARE_GET_SET(float, horizontal_lerp)
        PLANAR_DECLARE_GET_SET(float, vertical_lerp)

    private:
        virtual void load_impl(
            Engine::Component::CameraController2D& camera_controller)
            override;
    };
}
