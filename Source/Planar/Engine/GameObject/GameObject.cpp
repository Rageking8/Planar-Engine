#include "Planar/Engine/GameObject/GameObject.hpp"
#include "Planar/Engine/Core/GUID/GUID.hpp"
#include "Planar/Engine/Core/Utils/Checks/Assert.hpp"
#include "Planar/Engine/Core/Utils/Checks/Fatal.hpp"
#include "Planar/Engine/Core/Utils/Stack/Stack.hpp"
#include "Planar/Engine/Component/Core/AllComponent.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

#include <cstddef>
#include <unordered_set>

#define PLANAR_LOAD_COMPONENT_BEGIN_IF if (false) {}

#define PLANAR_LOAD_COMPONENT_ELSE_IF(component)    \
    else if (type == Component::component::NAME)    \
    {                                               \
        add_component<Component::component>({ i }); \
    }                                               \

namespace Planar::Engine::GameObject
{
    GameObject::GameObject(Scene::Scene* scene,
        const std::string& name) : active{ true },
        scene{ scene }, parent{}, name{ name }
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

                PLANAR_LOAD_COMPONENT_BEGIN_IF
                PLANAR_ALL_COMPONENT(PLANAR_LOAD_COMPONENT_ELSE_IF)
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
                std::make_shared<GameObject>(scene));
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

    bool GameObject::active_self() const
    {
        return active;
    }

    bool GameObject::active_in_hierarchy() const
    {
        const GameObject* game_object = this;
        while (game_object)
        {
            if (!game_object->active_self())
            {
                return false;
            }

            game_object = game_object->parent;
        }

        return true;
    }

    void GameObject::set_active(bool new_active)
    {
        active = new_active;
    }

    Scene::Scene* GameObject::get_scene() const
    {
        return scene;
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

    const std::string& GameObject::get_guid() const
    {
        return guid;
    }

    std::vector<std::shared_ptr<Component::Core::ComponentBase>>&
        GameObject::get_components()
    {
        return components;
    }

    std::shared_ptr<Component::Transform2D> GameObject::get_transform()
        const
    {
        PLANAR_ASSERT_NOT_EMPTY(components);
        PLANAR_ASSERT(components[0]->get_type() ==
            Component::Core::ComponentType::Transform2D,
            "`Transform2D` component should always be present");

        return std::static_pointer_cast<Component::Transform2D>(
            components[0]);
    }

    int GameObject::find_component(const std::string& guid,
        bool fatal_if_not_found)
    {
        return find_by_guid(components, guid, fatal_if_not_found);
    }

    void GameObject::remove_component(const std::string& guid)
    {
        const int index = find_component(guid, true);

        asset.remove_component(static_cast<std::size_t>(index));
        components.erase(components.begin() + index);
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

        children.push_back(std::make_shared<GameObject>(scene, name));
        std::shared_ptr<GameObject>& child = children.back();
        child->parent = is_root ? nullptr : this;

        child->add_component<Component::Transform2D>({}, true);

        child->asset.load(*child);
        asset.add_child(child->asset.get_asset());
    }

    void GameObject::remove_child(const std::string& guid)
    {
        const int index = find_child(guid, true);

        asset.remove_child(static_cast<std::size_t>(index));
        children.erase(children.begin() + index);
    }

    int GameObject::find_child(const std::string& guid,
        bool fatal_if_not_found)
    {
        return find_by_guid(children, guid, fatal_if_not_found);
    }

    void GameObject::clear_all_children()
    {
        children.clear();
    }

    std::shared_ptr<GameObject> GameObject::find_game_object(
        const std::string& guid)
    {
        std::shared_ptr<GameObject> result;

        iterate_depth_first([&](GameObject* current)
            {
                int find_result = current->find_child(guid);

                if (find_result != -1)
                {
                    std::shared_ptr<GameObject> child =
                        current->get_children()[find_result];
                    result = child;

                    return true;
                }

                return false;
            }, false);

        return result;
    }

    void GameObject::iterate_depth_first(
        const std::function<bool(GameObject*)>& callback,
        bool skip_empty)
    {
        std::stack<GameObject*> game_object_stack;
        game_object_stack.push(this);

        while (!game_object_stack.empty())
        {
            auto* current = Core::Utils::Stack::pop(game_object_stack);

            if (!(skip_empty && current->is_empty()))
            {
                if (callback(current))
                {
                    return;
                }
            }

            Core::Utils::Stack::push_raw_pointers_reverse(
                game_object_stack, current->get_children());
        }
    }

    void GameObject::iterate_depth_first(
        const std::function<bool(std::shared_ptr
        <Component::Core::ComponentBase>)>& callback, bool skip_empty)
    {
        iterate_depth_first([&](GameObject* game_object)
            {
                for (const auto& i : game_object->get_components())
                {
                    if (callback(i))
                    {
                        return true;
                    }
                }

                return false;
            }, skip_empty);
    }
}
