#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Scene/SceneAsset.hpp"
#include "Planar/Engine/GameObject/GameObject.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>
#include <memory>
#include <filesystem>

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Core, Application)
PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Component, Camera2D)

namespace Planar::Engine::Scene
{
    class PLANAR_API Scene
    {
    public:
        Scene(Core::Application* application);
        Scene(Core::Application* application,
            const std::string& scene_name,
            const std::string& asset_string);
        Scene(Core::Application* application,
            const std::filesystem::path& scene_path);
        virtual ~Scene();

        void load(const std::string& scene_name,
            const std::string& asset_string);
        void load(const std::filesystem::path& scene_path);
        void reload_from_path();
        void save();

        virtual void init();
        virtual void start();

        virtual void update();
        virtual void late_update();
        virtual void editor_update();

        virtual void render();

        virtual std::string get_name() const;

        Core::Application* get_application() const;
        SceneAsset& get_asset();
        std::shared_ptr<GameObject::GameObject> get_root();
        std::shared_ptr<Component::Camera2D> get_active_main_camera();

        std::shared_ptr<Component::Core::ComponentBase>
            get_component_reference(const std::string& guid) const;

        template <typename ComponentT>
        std::shared_ptr<ComponentT> get_component_reference(
            const std::string& guid) const;

    private:
        Core::Application* application;
        SceneAsset asset;
        std::shared_ptr<GameObject::GameObject> root;

        bool found_main_camera;
        std::weak_ptr<Component::Core::ComponentBase>
            active_main_camera;

        void load_root();

        void update_main_camera(
            std::shared_ptr<Component::Core::ComponentBase> component);
    };
}

#include "Planar/Engine/Scene/Scene.tpp"
