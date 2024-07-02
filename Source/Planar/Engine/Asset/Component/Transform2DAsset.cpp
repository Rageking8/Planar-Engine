#include "Planar/Engine/Asset/Component/Transform2DAsset.hpp"
#include "Planar/Engine/Component/Transform2D.hpp"

namespace Planar::Engine::Asset::Component
{
    Transform2DAsset::Transform2DAsset()
    {

    }

    Math::Pos2Df Transform2DAsset::get_position() const
    {
        return get_float_2("Position", "X", "Y");
    }

    void Transform2DAsset::set_position(Math::Pos2Df new_position)
    {
        set_float_2("Position", "X", "Y", new_position.get_array());
    }

    float Transform2DAsset::get_rotation() const
    {
        return get_float("Rotation");
    }

    void Transform2DAsset::set_rotation(float new_rotation)
    {
        set_float("Rotation", new_rotation);
    }

    Math::Size2Df Transform2DAsset::get_scale() const
    {
        return get_float_2("Scale", "Width", "Height");
    }

    void Transform2DAsset::set_scale(Math::Size2Df new_scale)
    {
        set_float_2("Scale", "Width", "Height",
            new_scale.get_array());
    }

    void Component::Transform2DAsset::load_impl(
        Engine::Component::Transform2D& transform)
    {
        set_position(transform.get_position());
        set_rotation(transform.get_rotation());
        set_scale(transform.get_scale());
    }
}
