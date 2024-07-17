#include "Planar/Engine/Component/Core/ComponentBase.hpp"
#include "Planar/Engine/GameObject/GameObject.hpp"
#include "Planar/Engine/Scene/Scene.hpp"

#include <memory>

namespace Planar::Engine::Component::Core
{
    template <typename ComponentT>
    inline std::shared_ptr<ComponentT> ComponentBase::get_component()
    {
        return get_parent()->get_component<ComponentT>();
    }

    template <typename ComponentT>
    inline std::shared_ptr<ComponentT>
        ComponentBase::get_component_reference(const std::string& guid)
        const
    {
        return get_parent()->get_scene()->
            get_component_reference<ComponentT>(guid);
    }
}
