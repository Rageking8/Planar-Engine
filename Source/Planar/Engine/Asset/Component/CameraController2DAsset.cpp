#include "Planar/Engine/Asset/Component/CameraController2DAsset.hpp"
#include "Planar/Engine/Asset/Component/Core/ComponentAssetMacros.hpp"
#include "Planar/Engine/Component/CameraController2D.hpp"

namespace Planar::Engine::Asset::Component
{
    CameraController2DAsset::CameraController2DAsset()
    {

    }

    PLANAR_DEFINE_COMPONENT_ASSET_GET_SET_VALUE(CameraController2D,
        std::string, mode, Mode)
    PLANAR_DEFINE_COMPONENT_ASSET_GET_SET_FLOAT_2(CameraController2D,
        Math::Size2Df, horizontal_speed, HorizontalSpeed, Left, Right)
    PLANAR_DEFINE_COMPONENT_ASSET_GET_SET_FLOAT_2(CameraController2D,
        Math::Size2Df, vertical_speed, VerticalSpeed, Up, Down)
    PLANAR_DEFINE_COMPONENT_ASSET_GET_SET_VALUE(CameraController2D,
        std::string, tracked_transform, TrackedTransform)
    PLANAR_DEFINE_COMPONENT_ASSET_GET_SET_VALUE(CameraController2D,
        float, horizontal_lerp, HorizontalLerp)
    PLANAR_DEFINE_COMPONENT_ASSET_GET_SET_VALUE(CameraController2D,
        float, vertical_lerp, VerticalLerp)

    void CameraController2DAsset::load_impl(
        Engine::Component::CameraController2D& camera_controller)
    {
        set_mode(camera_controller.get_mode());
        set_horizontal_speed(camera_controller.get_horizontal_speed());
        set_vertical_speed(camera_controller.get_vertical_speed());
        set_tracked_transform(camera_controller.get_tracked_transform());
        set_horizontal_lerp(camera_controller.get_horizontal_lerp());
        set_vertical_lerp(camera_controller.get_vertical_lerp());
    }
}
