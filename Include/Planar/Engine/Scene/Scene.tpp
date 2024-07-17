#include "Planar/Engine/Scene/Scene.hpp"

#include <memory>

namespace Planar::Engine::Scene
{
    template <typename ComponentT>
    inline std::shared_ptr<ComponentT> Scene::get_component_reference(
        const std::string& guid) const
    {
        return std::static_pointer_cast<ComponentT>(
            get_component_reference(guid));
    }
}
