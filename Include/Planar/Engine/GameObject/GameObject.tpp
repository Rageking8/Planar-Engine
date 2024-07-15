#include "Planar/Engine/GameObject/GameObject.hpp"
#include "Planar/Engine/Core/Utils/Checks/Fatal.hpp"

#include <memory>

namespace Planar::Engine::GameObject
{
    template <typename ComponentT>
    inline std::shared_ptr<ComponentT> GameObject::get_component()
    {
        for (auto& component : components)
        {
            if (component->match(ComponentT::TYPE))
            {
                return std::static_pointer_cast<ComponentT>(component);
            }
        }

        return nullptr;
    }

    template <typename ComponentT>
    inline void GameObject::add_component(
        std::optional<YAML::Node> node, bool skip_asset)
    {
        std::shared_ptr<ComponentT> new_component =
            std::make_shared<ComponentT>(this, !node);

        if (node)
        {
            new_component->load(*node);
        }
        else
        {
            new_component->load_asset();

            if (!skip_asset)
            {
                asset.add_component(new_component->get_node());
            }
        }

        components.push_back(new_component);
    }

    template <typename T>
    inline int GameObject::find_by_guid(
        std::vector<std::shared_ptr<T>>& vector,
        const std::string& guid, bool fatal_if_not_found)
    {
        for (std::size_t i = 0; i < vector.size(); ++i)
        {
            if (guid == vector[i]->get_guid())
            {
                return static_cast<int>(i);
            }
        }

        if (fatal_if_not_found)
        {
            PLANAR_FATAL("`guid` not found in `vector`");
        }

        return -1;
    }
}
