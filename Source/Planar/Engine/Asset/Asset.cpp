#include "Planar/Engine/Asset/Asset.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

namespace Planar::Engine::Asset
{
    Asset::Asset() : asset(std::make_unique<YAML::Node>())
    {

    }

    Asset::~Asset()
    {

    }

    YAML::Node Asset::get_asset() const
    {
        return *asset;
    }
}
