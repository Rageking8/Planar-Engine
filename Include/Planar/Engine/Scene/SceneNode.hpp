#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/GameObject/GameObject.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

#include <stack>
#include <string>
#include <vector>
#include <memory>
#include <optional>

namespace Planar::Engine::Scene
{
    class PLANAR_API SceneNode
    {
    public:
        SceneNode();

        void load(YAML::Node root,
            std::shared_ptr<std::stack<std::vector<SceneNode>*>>
            node_stack_ptr = nullptr);

        bool is_root_node() const;
        bool is_leaf_node() const;

        SceneNode* get_parent() const;
        GameObject::GameObject& get_game_object();
        std::shared_ptr<std::vector<SceneNode>> get_children();

        void add_child(std::string name = "");
        void remove_child(const std::string& guid);

    private:
        YAML::Node node;
        SceneNode* parent;
        std::optional<GameObject::GameObject> game_object;
        std::shared_ptr<std::vector<SceneNode>> children;
    };
}
