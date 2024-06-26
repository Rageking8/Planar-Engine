#include "Planar/Engine/Asset/Component/Camera2DAsset.hpp"
#include "Planar/Engine/Component/Camera2D.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

namespace Planar::Engine::Asset::Component
{
    Camera2DAsset::Camera2DAsset()
    {

    }

    void Camera2DAsset::load(Engine::Component::Camera2D& camera)
    {
        get("Type") = camera.NAME;
        get("GUID") = camera.get_guid();
    }

    std::string Camera2DAsset::get_guid() const
    {
        return get_scalar("GUID");
    }
}
