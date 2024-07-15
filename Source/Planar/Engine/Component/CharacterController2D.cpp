#include "Planar/Engine/Component/CharacterController2D.hpp"
#include "Planar/Engine/Component/Transform2D.hpp"
#include "Planar/Engine/Core/Input/InputController.hpp"

namespace Planar::Engine::Component
{
    CharacterController2D::CharacterController2D(
        GameObject::GameObject* parent, bool generate_guid) :
        Component(parent, generate_guid), speed{ 0.1f }
    {

    }

    PLANAR_DEFINE_COMPONENT_GET_SET(CharacterController2D,
        float, speed)

    void CharacterController2D::load_impl()
    {
        set_speed(asset.get_speed());
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
