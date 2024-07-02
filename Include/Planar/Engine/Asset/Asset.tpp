#include "Planar/Engine/Asset/Asset.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

namespace Planar::Engine::Asset
{
    template <typename T>
    T Asset::get_value(const std::string& key1) const
    {
        return get(key1).as<T>();
    }

    template <typename T>
    T Asset::get_value(const std::string& key1,
        const std::string& key2) const
    {
        return get(key1, key2).as<T>();
    }

    template <typename T>
    void Asset::set_value(const std::string& key1, T value) const
    {
        get(key1) = value;
    }

    template <typename T>
    void Asset::set_value(const std::string& key1,
        const std::string& key2, T value) const
    {
        get(key1, key2) = value;
    }
}
