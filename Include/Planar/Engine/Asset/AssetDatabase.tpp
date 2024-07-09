#include "Planar/Engine/Asset/AssetDatabase.hpp"

namespace Planar::Engine::Asset
{
    template <typename T>
    inline void AssetDatabase::add_owning_asset(
        std::shared_ptr<T> asset)
    {
        owning_asset_map[asset->get_guid()] = asset;
    }
}
