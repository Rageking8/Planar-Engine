#include "Planar/Engine/Scene/Scene.hpp"

namespace Planar::Engine::Scene
{
    Scene::Scene()
    {

    }

    Scene::~Scene()
    {

    }

    void Scene::load(const std::string& scene_asset,
        const std::string& scene_name,
        const std::filesystem::path& asset_path)
    {
        asset.load(scene_asset, scene_name, asset_path);
        root.load(asset.get_hierarchy());
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

    SceneNode& Scene::get_root()
    {
        return root;
    }
}
