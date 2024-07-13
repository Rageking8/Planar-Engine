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
    std::array<T, 2> Asset::get_value_2(const std::string& key1,
        const std::string& key2, const std::string& key3) const
    {
        return { get_value<T>(key1, key2), get_value<T>(key1, key3) };
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

    template <typename T>
    void Asset::set_value_2(const std::string& key1,
        const std::string& key2, const std::string& key3,
        std::array<T, 2> array) const
    {
        set_value(key1, key2, array[0]);
        set_value(key1, key3, array[1]);
    }
}
