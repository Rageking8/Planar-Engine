#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Math/Size2D.hpp"
#include "Planar/Engine/Asset/Component/ComponentAsset.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"
#include "Planar/Engine/Asset/Component/Mixin/Active.hpp"

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Component, CameraController2D)

namespace Planar::Engine::Asset::Component
{
    class PLANAR_API CameraController2DAsset :
        public ComponentAsset<Engine::Component::CameraController2D,
        Mixin::Active>
    {
    public:
        CameraController2DAsset();

        Math::Size2Df get_horizontal_speed() const;
        void set_horizontal_speed(Math::Size2Df new_horizontal_speed);

        Math::Size2Df get_vertical_speed() const;
        void set_vertical_speed(Math::Size2Df new_vertical_speed);

    private:
        virtual void load_impl(
            Engine::Component::CameraController2D& camera_controller)
            override;
    };
}
