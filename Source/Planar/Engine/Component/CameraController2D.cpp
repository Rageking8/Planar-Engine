#include "Planar/Engine/Component/CameraController2D.hpp"
#include "Planar/Engine/Core/Input/InputController.hpp"
#include "Planar/Engine/Component/Transform2D.hpp"

namespace Planar::Engine::Component
{
    CameraController2D::CameraController2D(
        GameObject::GameObject* parent, bool generate_guid) :
        Component(parent, generate_guid), mode{ "Free" },
        horizontal_speed{ 10.f }, vertical_speed{ 10.f }
    {

    }

    PLANAR_DEFINE_COMPONENT_GET_SET(CameraController2D, std::string,
        mode)
    PLANAR_DEFINE_COMPONENT_GET_SET(CameraController2D, Math::Size2Df,
        horizontal_speed)
    PLANAR_DEFINE_COMPONENT_GET_SET(CameraController2D, Math::Size2Df,
        vertical_speed)

    void CameraController2D::load_impl()
    {
        set_mode(asset.get_mode());
        set_horizontal_speed(asset.get_horizontal_speed());
        set_vertical_speed(asset.get_vertical_speed());
    }

    void CameraController2D::update_impl()
    {
        auto& input_controller = get_input_controller();
        std::shared_ptr<Transform2D> transform = get_transform();

        if (mode == "Free")
        {
            if (input_controller.key_down('W'))
            {
                transform->translate_y(vertical_speed.first);
            }

            if (input_controller.key_down('A'))
            {
                transform->translate_x(-horizontal_speed.first);
            }

            if (input_controller.key_down('S'))
            {
                transform->translate_y(-vertical_speed.second);
            }

            if (input_controller.key_down('D'))
            {
                transform->translate_x(horizontal_speed.second);
            }
        }
    }
}
