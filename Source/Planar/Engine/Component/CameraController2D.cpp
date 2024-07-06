#include "Planar/Engine/Component/CameraController2D.hpp"
#include "Planar/Engine/Core/Input/InputController.hpp"
#include "Planar/Engine/Component/Transform2D.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

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

    void CameraController2D::load_impl(YAML::Node node)
    {

    }
}
