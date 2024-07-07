#include "Planar/Engine/Asset/Component/CameraController2DAsset.hpp"
#include "Planar/Engine/Asset/Component/ComponentAssetMacros.hpp"
#include "Planar/Engine/Component/CameraController2D.hpp"

namespace Planar::Engine::Asset::Component
{
    CameraController2DAsset::CameraController2DAsset()
    {

    }

    PLANAR_DEFINE_COMPONENT_ASSET_GET_SET_FLOAT_2(CameraController2D,
        Math::Size2Df, horizontal_speed, HorizontalSpeed, Left, Right)
    PLANAR_DEFINE_COMPONENT_ASSET_GET_SET_FLOAT_2(CameraController2D,
        Math::Size2Df, vertical_speed, VerticalSpeed, Up, Down)

    void CameraController2DAsset::load_impl(
        Engine::Component::CameraController2D& camera_controller)
    {
        set_horizontal_speed(camera_controller.get_horizontal_speed());
        set_vertical_speed(camera_controller.get_vertical_speed());
    }
}
