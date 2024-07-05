#include "Planar/Engine/GameObject/GameObject.hpp"

namespace Planar::Engine::GameObject
{
    template <typename ComponentT>
    inline void GameObject::add_component(
        std::optional<YAML::Node> node)
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
            asset.add_component(new_component->get_node());
        }

        components.push_back(new_component);
    }
}
