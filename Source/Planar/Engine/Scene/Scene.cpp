#include "Planar/Engine/Scene/Scene.hpp"
#include "Planar/Engine/Component/ComponentBase.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

#include <stack>

namespace Planar::Engine::Scene
{
    Scene::Scene(Core::Application* application) :
        application{ application },
        root(std::make_shared<GameObject::GameObject>(this))
    {

    }

    Scene::Scene(Core::Application* application,
        const std::string& scene_asset,
        const std::string& scene_name,
        const std::filesystem::path& asset_path) :
        Scene(application)
    {
        load(application, scene_asset, scene_name, asset_path);
    }

    Scene::~Scene()
    {

    }

    void Scene::load(Core::Application* application,
        const std::string& scene_asset,
        const std::string& scene_name,
        const std::filesystem::path& asset_path)
    {
        asset.load(scene_asset, scene_name, asset_path);

        load_root();
    }

    void Scene::reload_from_path()
    {
        asset.reload_from_path();

        root->clear_all_children();
        load_root();
    }

    void Scene::save()
    {
        asset.save();
    }

    void Scene::init()
    {

    }

    void Scene::start()
    {

    }

    void Scene::update()
    {
        root->iterate_depth_first([](Component::ComponentBase* component)
            {
                component->update();

                return false;
            });
    }

    void Scene::render()
    {

    }

    Core::Application* Scene::get_application() const
    {
        return application;
    }

    SceneAsset& Scene::get_asset()
    {
        return asset;
    }

    std::shared_ptr<GameObject::GameObject> Scene::get_root()
    {
        return root;
    }

    void Scene::load_root()
    {
        std::stack<std::vector<std::shared_ptr<GameObject::GameObject>>*>
            children_vector_stack;

        root->load(asset.get_hierarchy(), children_vector_stack);
    }
}
