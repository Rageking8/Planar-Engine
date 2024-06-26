#include "Planar/Engine/Asset/Component/Transform2DAsset.hpp"
#include "Planar/Engine/Component/Transform2D.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

namespace Planar::Engine::Asset::Component
{
    Transform2DAsset::Transform2DAsset()
    {

    }

    void Transform2DAsset::load(
        Engine::Component::Transform2D& transform)
    {
        get("Type") = transform.NAME;
        get("GUID") = transform.get_guid();
        set_position(transform.get_position());
        set_rotation(transform.get_rotation());
    }

    std::string Transform2DAsset::get_guid() const
    {
        return get_scalar("GUID");
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
}
