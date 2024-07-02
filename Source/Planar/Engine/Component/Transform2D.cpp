#include "Planar/Engine/Component/Transform2D.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

namespace Planar::Engine::Component
{
    Transform2D::Transform2D(GameObject::GameObject* parent,
        bool generate_guid) : Component(parent, generate_guid),
        rotation{}
    {

    }

    void Transform2D::load()
    {
        asset.load(*this);
    }

    void Transform2D::load(YAML::Node node)
    {
        asset.set_node(node);

        set_guid(asset.get_guid());
        set_position(asset.get_position());
        set_rotation(asset.get_rotation());
    }

    Math::Pos2Df Transform2D::get_position() const
    {
        return position;
    }

    void Transform2D::set_position(Math::Pos2Df new_position)
    {
        position = new_position;
        asset.set_position(new_position);
    }

    float Transform2D::get_rotation() const
    {
        return rotation;
    }

    void Transform2D::set_rotation(float new_rotation)
    {
        rotation = new_rotation;
        asset.set_rotation(new_rotation);
    }

    Transform2DAsset& Transform2D::get_asset()
    {
        return asset;
    }
}
