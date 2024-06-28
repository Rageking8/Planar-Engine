#include "Planar/Engine/Component/Transform2DAsset.hpp"
#include "Planar/Engine/Component/Transform2D.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

namespace Planar::Engine::Component
{
    Transform2DAsset::Transform2DAsset()
    {

    }

    void Transform2DAsset::load(YAML::Node node)
    {
        *asset = node;
    }

    void Transform2DAsset::load(Transform2D& transform)
    {
        get("Type") = transform.NAME;
        get("GUID") = transform.get_guid();
        get("Position", "X") = transform.get_position().x;
        get("Position", "Y") = transform.get_position().y;
        get("Rotation") = transform.get_rotation();
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

    float Transform2DAsset::get_rotation() const
    {
        return get_float("Rotation");
    }
}
