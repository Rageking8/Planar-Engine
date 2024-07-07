#include "Planar/Engine/Asset/Component/CameraController2DAsset.hpp"
#include "Planar/Engine/Component/CameraController2D.hpp"

namespace Planar::Engine::Asset::Component
{
    CameraController2DAsset::CameraController2DAsset()
    {

    }

    Math::Size2Df CameraController2DAsset::get_horizontal_speed() const
    {
        return get_float_2("HorizontalSpeed", "Left", "Right");
    }

    void CameraController2DAsset::set_horizontal_speed(
        Math::Size2Df new_horizontal_speed)
    {
        set_float_2("HorizontalSpeed", "Left", "Right",
            new_horizontal_speed.get_array());
    }

    Math::Size2Df CameraController2DAsset::get_vertical_speed() const
    {
        return get_float_2("VerticalSpeed", "Up", "Down");
    }

    void CameraController2DAsset::set_vertical_speed(
        Math::Size2Df new_vertical_speed)
    {
        set_float_2("VerticalSpeed", "Up", "Down",
            new_vertical_speed.get_array());
    }

    void CameraController2DAsset::load_impl(
        Engine::Component::CameraController2D& camera_controller)
    {
        set_horizontal_speed(camera_controller.get_horizontal_speed());
        set_vertical_speed(camera_controller.get_vertical_speed());
    }
}
