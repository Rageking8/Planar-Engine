#include "Planar/Editor/UI/Element/Component/Component.hpp"
#include "Planar/Engine/Component/Core/ComponentBase.hpp"
#include "Planar/Engine/Component/Core/ComponentFunction.hpp"

namespace Planar::Editor::UI::Element::Component
{
    template <typename ComponentT>
    inline void Component<ComponentT>::set_values_impl(
        std::shared_ptr<Engine::Component::Core::ComponentBase>&
        component)
    {
        set_values_impl(cast(component));
    }

    template <typename ComponentT>
    inline void Component<ComponentT>::write_values_impl(
        std::shared_ptr<Engine::Component::Core::ComponentBase>&
        component)
    {
        write_values_impl(cast(component));
    }

    template <typename ComponentT>
    inline typename Component<ComponentT>::ComponentType*
        Component<ComponentT>::cast(
        std::shared_ptr<Engine::Component::Core::ComponentBase>&
        component) const
    {
        return Engine::Component::Core::component_downcast
            <ComponentType>(component);
    }
}
