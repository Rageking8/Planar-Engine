#include "Planar/Engine/Asset/Asset.hpp"

namespace Planar::Engine::Asset
{
    Asset::Asset()
    {

    }

    Asset::~Asset()
    {

    }

    YAML::Node Asset::get_asset() const
    {
        return asset;
    }
}
