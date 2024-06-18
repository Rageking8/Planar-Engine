#include "Planar/Engine/Scene/SceneNode.hpp"

namespace Planar::Engine::Scene
{
    SceneNode::SceneNode() :
        children{ std::make_shared<std::vector<SceneNode>>() }
    {

    }

    void SceneNode::load(YAML::Node root,
        std::shared_ptr<std::stack<std::vector<SceneNode>*>>
        node_stack_ptr)
    {
        node = root;

        if (root.size() == 0)
        {
            return;
        }

        YAML::Node loop_sequence;
        if (!node_stack_ptr)
        {
            node_stack_ptr = std::make_shared<std::stack<
                std::vector<SceneNode>*>>();
            loop_sequence = node;
        }
        else
        {
            loop_sequence = node["Children"];
        }

        node_stack_ptr->push(children.get());

        for (auto i : loop_sequence)
        {
            if (!i.IsMap())
            {
                continue;
            }

            node_stack_ptr->top()->push_back({});
            SceneNode& scene_node = node_stack_ptr->top()->back();
            scene_node.game_object = { { i["Name"].Scalar() } };
            scene_node.load(i, node_stack_ptr);
        }

        node_stack_ptr->pop();
    }

    bool SceneNode::is_root_node() const
    {
        return !game_object.has_value();
    }

    bool SceneNode::is_leaf_node() const
    {
        return children->empty();
    }

    Core::GameObject& SceneNode::get_game_object()
    {
        return *game_object;
    }

    std::shared_ptr<std::vector<SceneNode>> SceneNode::get_children()
    {
        return children;
    }

    void SceneNode::add_child(const std::string& name)
    {
        YAML::Node new_game_object;
        new_game_object["Name"] = name;
        new_game_object["Children"] = YAML::Node(YAML::NodeType::Null);

        (is_root_node() ? node : node["Children"]).
            push_back(new_game_object);

        children->push_back({});
        SceneNode& scene_node = children->back();
        scene_node.game_object = { { name } };
    }
}
