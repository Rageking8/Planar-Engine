#include "Planar/Engine/Component/CharacterController2D.hpp"

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
}
