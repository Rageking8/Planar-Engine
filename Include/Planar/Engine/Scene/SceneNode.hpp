#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Core/GameObject.hpp"

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

        Core::GameObject& get_game_object();
        std::shared_ptr<std::vector<SceneNode>> get_children();

        void add_child(std::string name = "");

    private:
        YAML::Node node;
        std::optional<Core::GameObject> game_object;
        std::shared_ptr<std::vector<SceneNode>> children;
    };
}
