#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/GameObject/GameObjectAsset.hpp"
#include "Planar/Engine/Component/Core/ComponentType.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <stack>
#include <string>
#include <vector>
#include <memory>
#include <optional>
#include <functional>

PLANAR_FORWARD_DECLARE_CLASS(YAML, Node)
PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Scene, Scene)
PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Component, Transform2D)
PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Component::Core, ComponentBase)

namespace Planar::Engine::GameObject
{
    class PLANAR_API GameObject
    {
    public:
        GameObject(Scene::Scene* scene, const std::string& name = "");

        void load(YAML::Node node,
            std::stack<std::vector<std::shared_ptr<GameObject>>*>&
            children_vector_stack);

        bool is_leaf() const;
        bool is_root() const;
        bool is_empty() const;

        bool active_self() const;
        bool active_in_hierarchy() const;

        void set_active(bool new_active);

        Scene::Scene* get_scene() const;

        GameObject* get_parent() const;

        std::string get_name() const;
        void set_name(const std::string& new_name);

        const std::string& get_guid() const;

        template <typename ComponentT>
        std::shared_ptr<ComponentT> get_component();

        std::vector<std::shared_ptr<Component::Core::ComponentBase>>&
            get_components();

        std::shared_ptr<Component::Transform2D> get_transform() const;

        template <typename ComponentT, typename... Args>
        void add_component(std::optional<YAML::Node> node = {},
            bool skip_asset = false, Args&... args);

        int find_component(const std::string& guid,
            bool fatal_if_not_found = false);
        void remove_component(const std::string& guid);

        std::vector<std::shared_ptr<GameObject>>& get_children();

        void add_child(std::string name = "");
        void remove_child(const std::string& guid);
        int find_child(const std::string& guid,
            bool fatal_if_not_found = false);
        void clear_all_children();

        std::shared_ptr<GameObject> find_game_object(
            const std::string& guid);

        void iterate_depth_first(
            const std::function<bool(GameObject*)>& callback,
            bool skip_empty = true, bool skip_inactive = true);
        void iterate_depth_first(
            const std::function<bool(
            std::shared_ptr<Component::Core::ComponentBase>)>&
            callback, bool skip_empty = true, bool skip_inactive = true);

    private:
        bool active;
        Scene::Scene* scene;
        GameObject* parent;
        std::string name;
        std::string guid;
        GameObjectAsset asset;
        std::vector<std::shared_ptr<Component::Core::ComponentBase>>
            components;
        std::vector<std::shared_ptr<GameObject>> children;

        template <typename T>
        int find_by_guid(std::vector<std::shared_ptr<T>>& vector,
            const std::string& guid, bool fatal_if_not_found = false);
    };
}

#include "Planar/Engine/GameObject/GameObject.tpp"
