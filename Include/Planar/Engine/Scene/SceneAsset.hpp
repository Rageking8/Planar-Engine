#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Asset/Asset.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

#include <string>
#include <filesystem>

namespace Planar::Engine::Scene
{
    class PLANAR_API SceneAsset : public Asset::Asset
    {
    public:
        SceneAsset();

        void create(std::string scene_asset,
            const std::filesystem::path& path,
            const std::string& scene_name);

        void load(const std::string& scene_asset,
            const std::string& scene_name,
            const std::filesystem::path& asset_path = {});

        std::string get_name() const;
        std::string get_guid() const;
        YAML::Node get_hierarchy();

    private:
        std::string name;
        YAML::Node asset;
        std::filesystem::path path;
    };
}
