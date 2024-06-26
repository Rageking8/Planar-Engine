#include "Planar/Engine/Scene/Scene.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

#include <stack>

namespace Planar::Engine::Scene
{
    Scene::Scene() :
        root(std::make_shared<GameObject::GameObject>())
    {

    }

    Scene::Scene(const std::string& scene_asset,
        const std::string& scene_name,
        const std::filesystem::path& asset_path) : Scene()
    {
        load(scene_asset, scene_name, asset_path);
    }

    Scene::~Scene()
    {

    }

    void Scene::load(const std::string& scene_asset,
        const std::string& scene_name,
        const std::filesystem::path& asset_path)
    {
        asset.load(scene_asset, scene_name, asset_path);

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

    }

    void Scene::render()
    {

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
