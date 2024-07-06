#include "Planar/Engine/Component/Camera2D.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

namespace Planar::Engine::Component
{
    Camera2D::Camera2D(GameObject::GameObject* parent,
        bool generate_guid) : Component(parent, generate_guid)
    {

    }

    void Camera2D::load_impl(YAML::Node node)
    {

    }
}
