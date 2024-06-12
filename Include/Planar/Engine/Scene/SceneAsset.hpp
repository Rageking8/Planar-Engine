#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Asset/Asset.hpp"

#include <string>
#include <filesystem>

namespace Planar::Engine::Scene
{
    class PLANAR_API SceneAsset : public Asset::Asset
    {
    public:
        SceneAsset();

        void create(const std::string& scene_asset,
            const std::filesystem::path& path,
            const std::string& scene_name);

        void load(const std::string& scene_asset,
            const std::string& scene_name);

        std::string get_name() const;
        std::string get_guid() const;

    private:
        std::string name;
        std::string asset;
    };
}
