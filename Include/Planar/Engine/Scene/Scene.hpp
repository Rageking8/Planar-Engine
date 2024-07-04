#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Scene/SceneAsset.hpp"
#include "Planar/Engine/GameObject/GameObject.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>
#include <memory>
#include <filesystem>

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Core, Application)

namespace Planar::Engine::Scene
{
    class PLANAR_API Scene
    {
    public:
        Scene(Core::Application* application = nullptr);
        Scene(Core::Application* application,
            const std::string& scene_asset,
            const std::string& scene_name,
            const std::filesystem::path& asset_path = {});
        virtual ~Scene();

        void load(Core::Application* application,
            const std::string& scene_asset,
            const std::string& scene_name,
            const std::filesystem::path& asset_path = {});
        void save();

        virtual void init();
        virtual void start();

        virtual void update();
        virtual void render();

        Core::Application* get_application() const;
        SceneAsset& get_asset();
        std::shared_ptr<GameObject::GameObject> get_root();

    private:
        Core::Application* application;
        SceneAsset asset;
        std::shared_ptr<GameObject::GameObject> root;

        void load_root();
    };
}
