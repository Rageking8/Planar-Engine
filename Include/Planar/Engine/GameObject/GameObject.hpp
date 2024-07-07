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

        Scene::Scene* get_scene() const;

        GameObject* get_parent() const;

        std::string get_name() const;
        void set_name(const std::string& new_name);

        std::string get_guid() const;

        std::vector<std::shared_ptr<Component::Core::ComponentBase>>&
            get_components();

        std::shared_ptr<Component::Transform2D> get_transform() const;

        template <typename ComponentT>
        void add_component(std::optional<YAML::Node> node = {});

        std::vector<std::shared_ptr<GameObject>>& get_children();

        void add_child(std::string name = "");
        void remove_child(const std::string& guid);
        int find_child(const std::string& guid);
        void clear_all_children();

        void iterate_depth_first(
            const std::function<bool(GameObject*)>& callback,
            bool skip_empty = true);
        void iterate_depth_first(
            const std::function<bool(
            std::shared_ptr<Component::Core::ComponentBase>)>&
            callback, bool skip_empty = true);

    private:
        Scene::Scene* scene;
        GameObject* parent;
        std::string name;
        std::string guid;
        GameObjectAsset asset;
        std::vector<std::shared_ptr<Component::Core::ComponentBase>>
            components;
        std::vector<std::shared_ptr<GameObject>> children;
    };
}

#include "Planar/Engine/GameObject/GameObject.tpp"
