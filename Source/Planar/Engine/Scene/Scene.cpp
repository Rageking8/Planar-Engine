#include "Planar/Engine/Scene/Scene.hpp"
#include "Planar/Engine/Component/Camera2D.hpp"
#include "Planar/Engine/Component/Core/ComponentBase.hpp"

#include <stack>

namespace Planar::Engine::Scene
{
    Scene::Scene(Core::Application* application) :
        application{ application },
        root(std::make_shared<GameObject::GameObject>(this)),
        found_main_camera{}
    {

    }

    Scene::Scene(Core::Application* application,
        const std::string& scene_name, const std::string& asset_string) :
        Scene(application)
    {
        load(application, scene_name, asset_string);
    }

    Scene::Scene(Core::Application* application,
        const std::filesystem::path& scene_path) :
        Scene(application)
    {
        load(application, scene_path);
    }

    Scene::~Scene()
    {

    }

    void Scene::load(Core::Application* application,
        const std::string& scene_name, const std::string& asset_string)
    {
        asset.load(scene_name, asset_string);
        load_root();
    }

    void Scene::load(Core::Application* application,
        const std::filesystem::path& scene_path)
    {
        if (scene_path.empty())
        {
            return;
        }

        asset.load(scene_path);

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
        found_main_camera = false;

        root->iterate_depth_first([&]
            (std::shared_ptr<Component::Core::ComponentBase> component)
            {
                update_main_camera(component);

                component->update();

                return false;
            });
    }

    void Scene::late_update()
    {
        root->iterate_depth_first([&]
            (std::shared_ptr<Component::Core::ComponentBase> component)
            {
                component->late_update();

                return false;
            });
    }

    void Scene::editor_update()
    {
        found_main_camera = false;

        root->iterate_depth_first([&]
            (std::shared_ptr<Component::Core::ComponentBase> component)
            {
                update_main_camera(component);

                return false;
            });
    }

    void Scene::render()
    {
        root->iterate_depth_first([&]
            (std::shared_ptr<Component::Core::ComponentBase> component)
            {
                component->render();

                return false;
            });
    }

    std::string Scene::get_name() const
    {
        return asset.get_name();
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

    std::shared_ptr<Component::Camera2D> Scene::get_active_main_camera()
    {
        std::shared_ptr<Component::Camera2D> camera =
            std::static_pointer_cast<Component::Camera2D>(
            active_main_camera.lock());

        if (!camera || !camera->get_active())
        {
            active_main_camera.reset();

            return nullptr;
        }

        return camera;
    }

    std::shared_ptr<Component::Core::ComponentBase>
        Scene::get_component_reference(const std::string& guid) const
    {
        std::shared_ptr<Component::Core::ComponentBase> result;

        root->iterate_depth_first([&]
            (std::shared_ptr<Component::Core::ComponentBase> component)
            {
                if (guid == component->get_guid())
                {
                    result = component;

                    return true;
                }

                return false;
            });

        return result;
    }

    void Scene::load_root()
    {
        std::stack<std::vector<std::shared_ptr<GameObject::GameObject>>*>
            children_vector_stack;

        root->load(asset.get_hierarchy(), children_vector_stack);
    }

    void Scene::update_main_camera(
        std::shared_ptr<Component::Core::ComponentBase> component)
    {
        if (found_main_camera || component->get_type() !=
            Component::Core::ComponentType::Camera2D)
        {
            return;
        }

        auto camera =
            std::static_pointer_cast<Component::Camera2D>(component);

        if (camera->get_active())
        {
            active_main_camera = camera;
            found_main_camera = true;
        }
    }
}
