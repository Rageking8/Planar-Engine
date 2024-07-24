#include "Planar/Engine/Asset/AssetDatabase.hpp"

namespace Planar::Engine::Asset
{
    template <typename T>
    inline void AssetDatabase::load_owning_asset(
        const std::filesystem::path& asset_path)
    {
        std::shared_ptr<T> asset = std::make_shared<T>();

        asset->load(asset_path);

        add_owning_asset(asset);
    }

    template <typename T>
    inline void AssetDatabase::create_owning_asset(
        const std::filesystem::path& asset_path)
    {
        std::shared_ptr<T> asset = std::make_shared<T>();

        asset->create(asset_path);
        asset->save();

        add_owning_asset(asset);
    }

    template <typename T>
    inline void AssetDatabase::add_owning_asset(
        std::shared_ptr<T> asset)
    {
        owning_asset_map[asset->get_guid()] = asset;
    }

    template <typename T>
    inline std::shared_ptr<T> AssetDatabase::get_owning_asset(
        const std::string& guid)
    {
        return std::static_pointer_cast<T>(owning_asset_map[guid]);
    }
}
