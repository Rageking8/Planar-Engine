#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Scene/SceneAsset.hpp"
#include "Planar/Engine/GameObject/GameObject.hpp"

#include <string>
#include <memory>
#include <filesystem>

namespace Planar::Engine::Scene
{
    class PLANAR_API Scene
    {
    public:
        Scene();
        Scene(const std::string& scene_asset,
            const std::string& scene_name,
            const std::filesystem::path& asset_path = {});
        virtual ~Scene();

        void load(const std::string& scene_asset,
            const std::string& scene_name,
            const std::filesystem::path& asset_path = {});
        void save();

        virtual void init();
        virtual void start();

        virtual void update();
        virtual void render();

        SceneAsset& get_asset();
        std::shared_ptr<GameObject::GameObject> get_root();

    private:
        SceneAsset asset;
        std::shared_ptr<GameObject::GameObject> root;

        void load_root();
    };
}
