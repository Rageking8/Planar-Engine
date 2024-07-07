#include "Planar/Engine/Component/CameraController2D.hpp"
#include "Planar/Engine/Core/Input/InputController.hpp"
#include "Planar/Engine/Component/Transform2D.hpp"

namespace Planar::Engine::Component
{
    CameraController2D::CameraController2D(
        GameObject::GameObject* parent,
        bool generate_guid) : Component(parent, generate_guid),
        horizontal_speed{ 10.f }, vertical_speed{ 10.f }
    {

    }

    void CameraController2D::update()
    {
        auto& input_controller = get_input_controller();
        std::shared_ptr<Transform2D> transform = get_transform();
        
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

    Math::Size2Df CameraController2D::get_horizontal_speed() const
    {
        return horizontal_speed;
    }

    void CameraController2D::set_horizontal_speed(
        Math::Size2Df new_horizontal_speed)
    {
        horizontal_speed = new_horizontal_speed;
        asset.set_horizontal_speed(new_horizontal_speed);
    }

    Math::Size2Df CameraController2D::get_vertical_speed() const
    {
        return vertical_speed;
    }

    void CameraController2D::set_vertical_speed(
        Math::Size2Df new_vertical_speed)
    {
        vertical_speed = new_vertical_speed;
        asset.set_vertical_speed(new_vertical_speed);
    }

    void CameraController2D::load_impl()
    {
        set_horizontal_speed(asset.get_horizontal_speed());
        set_vertical_speed(asset.get_vertical_speed());
    }
}
