#include "Planar/Engine/Scene/SceneNode.hpp"
#include "Planar/Engine/Core/Utils/Checks/Fatal.hpp"

#include <unordered_set>

namespace Planar::Engine::Scene
{
    SceneNode::SceneNode() : parent{},
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

            node_stack_ptr->top()->emplace_back();
            SceneNode& scene_node = node_stack_ptr->top()->back();
            scene_node.parent = this;
            scene_node.game_object.emplace(i["Name"].Scalar(),
                i["GUID"].Scalar());
            scene_node.load(i, node_stack_ptr);
        }

        node_stack_ptr->pop();
    }

    bool SceneNode::is_root_node() const
    {
        return !parent;
    }

    bool SceneNode::is_leaf_node() const
    {
        return children->empty();
    }

    SceneNode* SceneNode::get_parent() const
    {
        return parent;
    }

    Core::GameObject& SceneNode::get_game_object()
    {
        return *game_object;
    }

    std::shared_ptr<std::vector<SceneNode>> SceneNode::get_children()
    {
        return children;
    }

    void SceneNode::add_child(std::string name)
    {
        if (name.empty())
        {
            name = "GameObject";

            std::unordered_set<std::string> name_set;
            name_set.reserve(children->size());

            for (const auto& i : *children)
            {
                name_set.insert(i.game_object->get_name());
            }

            unsigned postfix = 1;
            while (name_set.contains(name + std::to_string(postfix)))
            {
                postfix++;
            }

            name += std::to_string(postfix);
        }

        children->emplace_back();
        SceneNode& scene_node = children->back();
        scene_node.parent = this;
        scene_node.game_object.emplace(name);
        Core::GameObject& object = *scene_node.game_object;

        YAML::Node new_game_object;
        new_game_object["Name"] = object.get_name();
        new_game_object["GUID"] = object.get_guid();
        new_game_object["Children"] = YAML::Node();

        (is_root_node() ? node : node["Children"]).
            push_back(new_game_object);
        scene_node.node = new_game_object;
    }

    void SceneNode::remove_child(const std::string& guid)
    {
        for (std::size_t i = 0; i < children->size(); ++i)
        {
            SceneNode& current = (*children)[i];

            if (guid == current.game_object->get_guid())
            {
                YAML::Node target = is_root_node() ? node :
                    node["Children"];
                target.remove(i);
                children->erase(children->begin() + i);

                if (children->empty())
                {
                    target = YAML::Node();
                }

                return;
            }
        }

        PLANAR_FATAL("No child with `guid` found");
    }
}
