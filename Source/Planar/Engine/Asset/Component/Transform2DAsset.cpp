#include "Planar/Engine/Asset/Component/Transform2DAsset.hpp"
#include "Planar/Engine/Asset/Component/ComponentAssetMacros.hpp"
#include "Planar/Engine/Component/Transform2D.hpp"

namespace Planar::Engine::Asset::Component
{
    Transform2DAsset::Transform2DAsset()
    {

    }

    PLANAR_DEFINE_COMPONENT_ASSET_GET_SET_FLOAT_2(Transform2D,
        Math::Pos2Df, position, Position, X, Y)
    PLANAR_DEFINE_COMPONENT_ASSET_GET_SET_VALUE(Transform2D,
        float, rotation, Rotation)
    PLANAR_DEFINE_COMPONENT_ASSET_GET_SET_FLOAT_2(Transform2D,
        Math::Size2Df, scale, Scale, Width, Height)

    void Component::Transform2DAsset::load_impl(
        Engine::Component::Transform2D& transform)
    {
        set_position(transform.get_position());
        set_rotation(transform.get_rotation());
        set_scale(transform.get_scale());
    }
}
