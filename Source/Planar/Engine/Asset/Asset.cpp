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

    void Asset::clear()
    {
        *asset = YAML::Node();
    }

    bool Asset::is_null() const
    {
        return asset->IsNull();
    }

    bool Asset::is_sequence() const
    {
        return asset->IsSequence();
    }

    YAML::Node Asset::get(const std::string& key) const
    {
        return (*asset)[key];
    }

    YAML::Node Asset::get_asset() const
    {
        return *asset;
    }

    std::string Asset::get_scalar(const std::string& key) const
    {
        return get(key).Scalar();
    }
}
