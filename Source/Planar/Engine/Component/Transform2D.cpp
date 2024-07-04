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
        set_scale(asset.get_scale());
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

    void Transform2D::translate(Math::Size2Df delta)
    {
        position.x += delta.width;
        position.y += delta.height;
        asset.set_position(position);
    }

    void Transform2D::translate_x(float delta)
    {
        translate({ delta, 0.f });
    }

    void Transform2D::translate_y(float delta)
    {
        translate({ 0.f, delta });
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

    Math::Size2Df Transform2D::get_scale() const
    {
        return scale;
    }

    void Transform2D::set_scale(Math::Size2Df new_scale)
    {
        scale = new_scale;
        asset.set_scale(new_scale);
    }

    Asset::Component::Transform2DAsset& Transform2D::get_asset()
    {
        return asset;
    }
}
