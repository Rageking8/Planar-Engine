#pragma once

#include "Planar/Editor/UI/Element/Component/ComponentBase.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <memory>

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Component::Core, ComponentBase)

namespace Planar::Editor::UI::Element::Component
{
    template <typename ComponentT>
    class Component : public ComponentBase
    {
    public:
        using ComponentType = ComponentT;

        using ComponentBase::ComponentBase;

    private:
        virtual void set_values_impl(
            std::shared_ptr<Engine::Component::Core::ComponentBase>&
            component) override;
        virtual void write_values_impl(
            std::shared_ptr<Engine::Component::Core::ComponentBase>&
            component) override;

        virtual void set_values_impl(ComponentType* component) = 0;
        virtual void write_values_impl(ComponentType* component) = 0;

        ComponentType* cast(
            std::shared_ptr<Engine::Component::Core::ComponentBase>&
            component) const;
    };
}

#include "Planar/Editor/UI/Element/Component/Component.tpp"
