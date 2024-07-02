#include "Planar/Engine/Component/Camera2D.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

namespace Planar::Engine::Component
{
    Camera2D::Camera2D(GameObject::GameObject* parent,
        bool generate_guid) : Component(parent, generate_guid)
    {

    }

    void Camera2D::load()
    {
        asset.load(*this);
    }

    void Camera2D::load(YAML::Node node)
    {
        asset.set_node(node);

        set_guid(asset.get_guid());
    }

    Asset::Component::Camera2DAsset& Camera2D::get_asset()
    {
        return asset;
    }
}
