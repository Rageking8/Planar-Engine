#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

#include <string>
#include <memory>
#include <cstddef>
#include <filesystem>
#include <unordered_map>

namespace Planar::Engine::Asset
{
    class PLANAR_API AssetDatabase
    {
    public:
        AssetDatabase();

        void load_sprite(const std::string& name,
            const std::string& asset, const unsigned char* sprite,
            std::size_t length);
        void load_asset_recursive(const std::filesystem::path& root);

        template <typename T>
        void create_owning_asset(const std::filesystem::path& asset_path);

        template <typename T>
        void add_owning_asset(std::shared_ptr<T> asset);

        template <typename T>
        std::shared_ptr<T> get_owning_asset(const std::string& guid);

    private:
        std::unordered_map<std::string, std::shared_ptr<void>>
            owning_asset_map;
    };
}

#include "Planar/Engine/Asset/AssetDatabase.tpp"
