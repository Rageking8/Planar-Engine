#include "Planar/Engine/Asset/Component/Transform2DAsset.hpp"
#include "Planar/Engine/Component/Transform2D.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

namespace Planar::Engine::Asset::Component
{
    Transform2DAsset::Transform2DAsset()
    {

    }

    Math::Pos2Df Transform2DAsset::get_position() const
    {
        return { get_float("Position", "X"),
            get_float("Position", "Y") };
    }

    void Transform2DAsset::set_position(Math::Pos2Df new_position)
    {
        get("Position", "X") = new_position.x;
        get("Position", "Y") = new_position.y;
    }

    float Transform2DAsset::get_rotation() const
    {
        return get_float("Rotation");
    }

    void Transform2DAsset::set_rotation(float new_rotation)
    {
        get("Rotation") = new_rotation;
    }

    Math::Size2Df Transform2DAsset::get_scale() const
    {
        return { get_float("Scale", "Width"),
            get_float("Scale", "Height") };
    }

    void Transform2DAsset::set_scale(Math::Size2Df new_scale)
    {
        get("Scale", "Width") = new_scale.width;
        get("Scale", "Height") = new_scale.height;
    }

    void Component::Transform2DAsset::load_impl(
        Engine::Component::Transform2D& transform)
    {
        set_position(transform.get_position());
        set_rotation(transform.get_rotation());
        set_scale(transform.get_scale());
    }
}
