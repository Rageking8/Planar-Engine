#include "Planar/Engine/Component/CharacterController2D.hpp"
#include "Planar/Engine/Component/Transform2D.hpp"
#include "Planar/Engine/Core/Input/InputController.hpp"

namespace Planar::Engine::Component
{
    CharacterController2D::CharacterController2D(
        GameObject::GameObject* parent, bool generate_guid) :
        Component(parent, generate_guid), speed{ 0.1f },
        enable_x_flip{ true }, inverse_x_flip{ false }
    {

    }

    PLANAR_DEFINE_COMPONENT_GET_SET(CharacterController2D,
        float, speed)
    PLANAR_DEFINE_COMPONENT_GET_SET(CharacterController2D,
        bool, enable_x_flip)
    PLANAR_DEFINE_COMPONENT_GET_SET(CharacterController2D,
        bool, inverse_x_flip)

    void CharacterController2D::load_impl()
    {
        set_speed(asset.get_speed());
        set_enable_x_flip(asset.get_enable_x_flip());
        set_inverse_x_flip(asset.get_inverse_x_flip());
    }

    void CharacterController2D::update_impl()
    {
        auto& input_controller = get_input_controller();
        std::shared_ptr<Transform2D> transform = get_transform();

        if (input_controller.key_down('W'))
        {
            transform->translate_y(speed);
        }

        if (input_controller.key_down('A'))
        {
            transform->translate_x(-speed);
        }

        if (input_controller.key_down('S'))
        {
            transform->translate_y(-speed);
        }

        if (input_controller.key_down('D'))
        {
            transform->translate_x(speed);
        }
    }
}
