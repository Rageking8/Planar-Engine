#include "Planar/Engine/Asset/Asset.hpp"
#include "Planar/Engine/Asset/AssetFunction.hpp"
#include "Planar/Engine/Core/Utils/Checks/Assert.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

namespace Planar::Engine::Asset
{
    Asset::Asset() : asset(std::make_unique<YAML::Node>())
    {

    }

    Asset::~Asset()
    {

    }

    void Asset::load(const std::string& asset_string)
    {
        *asset = YAML::Load(asset_string);
    }

    void Asset::load(const std::filesystem::path& asset_path)
    {
        PLANAR_ASSERT_NOT_EMPTY(asset_path);

        load(Core::FileSystem::read_file(asset_path));
    }

    void Asset::write(const std::filesystem::path& write_path) const
    {
        PLANAR_ASSERT_NOT_EMPTY(write_path);

        Core::FileSystem::create_file(write_path,
            Engine::Asset::to_string(*asset));
    }

    void Asset::set_node(YAML::Node node)
    {
        *asset = node;
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

    YAML::Node Asset::get(const std::string& key1) const
    {
        return (*asset)[key1];
    }

    YAML::Node Asset::get(const std::string& key1,
        const std::string& key2) const
    {
        return get(key1)[key2];
    }

    YAML::Node Asset::get_asset() const
    {
        return *asset;
    }

    std::array<float, 2> Asset::get_float_2(const std::string& key1,
        const std::string& key2, const std::string& key3) const
    {
        return { get_value<float>(key1, key2),
            get_value<float>(key1, key3) };
    }

    void Asset::set_float_2(const std::string& key1,
        const std::string& key2, const std::string& key3,
        std::array<float, 2> array) const
    {
        set_value(key1, key2, array[0]);
        set_value(key1, key3, array[1]);
    }
}
