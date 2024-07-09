#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

#include <string>
#include <memory>
#include <unordered_map>

namespace Planar::Engine::Asset
{
    class PLANAR_API AssetDatabase
    {
    public:
        AssetDatabase();

        template <typename T>
        void add_owning_asset(std::shared_ptr<T> asset);

    private:
        std::unordered_map<std::string, std::shared_ptr<void>>
            owning_asset_map;
    };
}

#include "Planar/Engine/Asset/AssetDatabase.tpp"
