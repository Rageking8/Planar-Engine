#include "Planar/Editor/UI/Element/Component/Core/Component.hpp"
#include "Planar/Engine/Component/Core/ComponentBase.hpp"
#include "Planar/Engine/Component/Core/ComponentFunction.hpp"

namespace Planar::Editor::UI::Element::Component::Core
{
    template <typename ComponentT>
    inline Component<ComponentT>::Component(bool show_active_checkbox) :
        ComponentBase(ComponentT::NAME, show_active_checkbox)
    {

    }

    template <typename ComponentT>
    template <typename... Args>
    inline bool Component<ComponentT>::modified_helper(
        bool reset, Args&... args)
    {
        bool result = false;

        ([&]
            {
                // Avoid short circuiting and evaluate all arguments
                bool current = args.get_modified(reset);
                result = result || current;
            }(), ...);

        return result;
    }

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
