#include "Planar/Engine/Component/Camera2D.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

namespace Planar::Engine::Component
{
    Camera2D::Camera2D(bool generate_guid) :
        Component(generate_guid)
    {

    }

    void Camera2D::load()
    {
        asset.load(*this);
    }

    void Camera2D::load(YAML::Node node)
    {
        asset.load(node);

        set_guid(asset.get_guid());
    }

    Camera2DAsset& Camera2D::get_asset()
    {
        return asset;
    }
}
