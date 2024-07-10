#include "Planar/Engine/Asset/AssetDatabase.hpp"

namespace Planar::Engine::Asset
{
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
