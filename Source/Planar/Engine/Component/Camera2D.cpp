#include "Planar/Engine/Component/Camera2D.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

namespace Planar::Engine::Component
{
    Camera2D::Camera2D(GameObject::GameObject* parent,
        bool generate_guid) : Component(parent, generate_guid),
        active{ true }
    {

    }

    void Camera2D::load(YAML::Node node)
    {
        asset.set_node(node);

        set_guid(asset.get_guid());
        set_active(asset.get_active());
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

    void Camera2D::load_asset()
    {
        asset.load(*this);
    }

    const Asset::Component::Camera2DAsset& Camera2D::get_asset() const
    {
        return asset;
    }
}
