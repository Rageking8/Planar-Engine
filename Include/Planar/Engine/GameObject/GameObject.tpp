#include "Planar/Engine/GameObject/GameObject.hpp"

namespace Planar::Engine::GameObject
{
    template <typename ComponentT>
    inline void GameObject::add_component()
    {
        std::shared_ptr<ComponentT> new_component =
            std::make_shared<ComponentT>(this);
        new_component->load_asset();
        components.push_back(new_component);
        asset.add_component(new_component->get_node());
    }
}
