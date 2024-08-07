#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Asset/Asset.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>
#include <filesystem>

PLANAR_FORWARD_DECLARE_CLASS(YAML, Node)

namespace Planar::Engine::Scene
{
    class PLANAR_API SceneAsset : public Asset::Asset
    {
    public:
        SceneAsset();

        void create(std::string scene_asset,
            const std::filesystem::path& path,
            const std::string& scene_name);

        void load(const std::string& scene_name,
            const std::string& asset_string);
        virtual void load(const std::filesystem::path& scene_path)
            override;
        void reload_from_path();
        void save();

        virtual std::string get_name() const override;
        YAML::Node get_hierarchy();

    private:
        std::string name;
        std::filesystem::path path;
    };
}
