#include "Planar/Editor/UI/Element/Component.hpp"
#include "Planar/Engine/Component/Component.hpp"
#include "Planar/Engine/Component/ComponentFunction.hpp"

namespace Planar::Editor::UI::Element
{
    template <typename ComponentT>
    inline void Component<ComponentT>::set_values_impl(
        std::shared_ptr<Engine::Component::Component>& component)
    {
        set_values_impl(cast(component));
    }

    template <typename ComponentT>
    inline void Component<ComponentT>::write_values_impl(
        std::shared_ptr<Engine::Component::Component>& component)
    {
        write_values_impl(cast(component));
    }

    template <typename ComponentT>
    inline typename Component<ComponentT>::ComponentType*
        Component<ComponentT>::cast(
        std::shared_ptr<Engine::Component::Component>& component) const
    {
        return Engine::Component::component_downcast<ComponentType>(
            component);
    }
}
