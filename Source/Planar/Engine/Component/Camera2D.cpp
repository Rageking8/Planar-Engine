#include "Planar/Engine/Component/Camera2D.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

namespace Planar::Engine::Component
{
    Camera2D::Camera2D(GameObject::GameObject* parent,
        bool generate_guid) : Component(parent, generate_guid),
        active{ true }
    {

    }

    bool Camera2D::get_active() const
    {
        return active;
    }

    void Camera2D::set_active(bool new_active)
    {
        active = new_active;
        asset.set_active(new_active);
    }

    void Camera2D::load_impl(YAML::Node node)
    {
        set_active(asset.get_active());
    }
}
