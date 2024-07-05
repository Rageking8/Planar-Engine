#include "Planar/Engine/Component/CameraController2D.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

namespace Planar::Engine::Component
{
    CameraController2D::CameraController2D(
        GameObject::GameObject* parent,
        bool generate_guid) : Component(parent, generate_guid),
        active{ true }
    {

    }

    bool CameraController2D::get_active() const
    {
        return active;
    }

    void CameraController2D::set_active(bool new_active)
    {
        active = new_active;
        asset.set_active(new_active);
    }

    void CameraController2D::load_impl(YAML::Node node)
    {
        set_active(asset.get_active());
    }
}
