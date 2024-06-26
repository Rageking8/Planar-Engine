#include "Planar/Engine/GameObject/GameObject.hpp"
#include "Planar/Engine/Core/Utils/Checks/Fatal.hpp"
#include "Planar/Engine/Core/GUID/GUID.hpp"
#include "Planar/Engine/Core/Utils/Checks/Fatal.hpp"
#include "Planar/Engine/Component/Transform2D.hpp"
#include "Planar/Engine/Component/Camera2D.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

#include <cstddef>
#include <unordered_set>

namespace Planar::Engine::GameObject
{
    GameObject::GameObject(const std::string& name) :
        parent{}, name{ name }
    {
        if (!name.empty())
        {
            guid = Core::GUID::generate_guid(
                Core::GUID::Representation::DEFAULT_COMPACT);
        }
    }

    void GameObject::load(YAML::Node node,
        std::stack<std::vector<std::shared_ptr<GameObject>>*>&
        children_vector_stack)
    {
        asset.set_node(node);

        if (node.size() == 0)
        {
            return;
        }

        const bool is_root = node.IsSequence();

        children_vector_stack.push(&children);

        if (!is_root)
        {
            name = asset.get_name();
            guid = asset.get_guid();

            for (auto i : node["Components"])
            {
                if (!i.IsMap())
                {
                    continue;
                }

                std::string type = i["Type"].Scalar();

                if (type == Component::Transform2D::NAME)
                {
                    std::shared_ptr<Component::Transform2D> transform =
                        std::make_shared<Component::Transform2D>(
                        this, false);
                    transform->load(i);
                    components.push_back(transform);
                }
                else if (type == Component::Camera2D::NAME)
                {
                    std::shared_ptr<Component::Camera2D> camera =
                        std::make_shared<Component::Camera2D>(this, false);
                    camera->load(i);
                    components.push_back(camera);
                }
                else
                {
                    PLANAR_FATAL("Unrecognized component type");
                }
            }
        }

        for (auto i : (is_root ? node : node["Children"]))
        {
            if (!i.IsMap())
            {
                continue;
            }

            children_vector_stack.top()->push_back(
                std::make_shared<GameObject>());
            std::shared_ptr<GameObject>& game_object =
                children_vector_stack.top()->back();
            game_object->parent = is_root ? nullptr : this;
            game_object->load(i, children_vector_stack);
        }

        children_vector_stack.pop();
    }

    bool GameObject::is_leaf() const
    {
        return children.empty();
    }

    bool GameObject::is_root() const
    {
        return !parent;
    }

    bool GameObject::is_empty() const
    {
        return name.empty() && guid.empty();
    }

    GameObject* GameObject::get_parent() const
    {
        return parent;
    }

    std::string GameObject::get_name() const
    {
        return name;
    }

    void GameObject::set_name(const std::string& new_name)
    {
        name = new_name;
        asset.set_name(new_name);
    }

    std::string GameObject::get_guid() const
    {
        return guid;
    }

    std::vector<std::shared_ptr<Component::Component>>&
        GameObject::get_components()
    {
        return components;
    }

    void GameObject::add_component(Component::ComponentType type)
    {
        switch (type)
        {
        case Component::ComponentType::Transform2D:
        {
            std::shared_ptr<Component::Transform2D> transform =
                std::make_shared<Component::Transform2D>(this);
            transform->load();
            components.push_back(transform);
            asset.add_component(transform->get_asset().get_asset());

            break;
        }

        case Component::ComponentType::Camera2D:
        {
            std::shared_ptr<Component::Camera2D> camera =
                std::make_shared<Component::Camera2D>(this);
            camera->load();
            components.push_back(camera);
            asset.add_component(camera->get_asset().get_asset());

            break;
        }
        }
    }

    std::vector<std::shared_ptr<GameObject>>& GameObject::get_children()
    {
        return children;
    }

    void GameObject::add_child(std::string name)
    {
        if (name.empty())
        {
            name = "GameObject";

            std::unordered_set<std::string> name_set;
            name_set.reserve(children.size());

            for (const auto& i : children)
            {
                name_set.insert(i->get_name());
            }

            unsigned postfix = 1;
            while (name_set.contains(name + std::to_string(postfix)))
            {
                postfix++;
            }

            name += std::to_string(postfix);
        }

        const bool is_root = asset.get_asset().IsNull() ||
            asset.get_asset().IsSequence();

        children.push_back(std::make_shared<GameObject>(name));
        std::shared_ptr<GameObject>& child = children.back();
        child->parent = is_root ? nullptr : this;

        child->add_component(Component::ComponentType::Transform2D);

        child->asset.load(*child);
        asset.add_child(child->asset.get_asset());
    }

    void GameObject::remove_child(const std::string& guid)
    {
        for (std::size_t i = 0; i < children.size(); ++i)
        {
            if (guid == children[i]->guid)
            {
                asset.remove_child(i);
                children.erase(children.begin() + i);

                return;
            }
        }

        PLANAR_FATAL("No child with `guid` found");
    }
}
