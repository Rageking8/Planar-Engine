#include "Planar/Engine/Component/CameraController2D.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

namespace Planar::Engine::Component
{
    CameraController2D::CameraController2D(
        GameObject::GameObject* parent,
        bool generate_guid) : Component(parent, generate_guid)
    {

    }

    void CameraController2D::load_impl(YAML::Node node)
    {

    }
}
