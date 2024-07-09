#include "Planar/Engine/Asset/Component/Camera2DAsset.hpp"
#include "Planar/Engine/Asset/Component/Core/ComponentAssetMacros.hpp"
#include "Planar/Engine/Component/Camera2D.hpp"

namespace Planar::Engine::Asset::Component
{
    Camera2DAsset::Camera2DAsset()
    {

    }

    PLANAR_DEFINE_COMPONENT_ASSET_GET_SET_VALUE(Camera2D,
        float, pixel_scale, PixelScale)

    void Camera2DAsset::load_impl(Engine::Component::Camera2D& camera)
    {
        set_pixel_scale(camera.get_pixel_scale());
    }
}
