#pragma once

#include "Planar/Editor/UI/Element/Component/Core/ComponentBase.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>
#include <memory>

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Component::Core, ComponentBase)

namespace Planar::Editor::UI::Element::Component::Core
{
    template <typename ComponentT>
    class Component : public ComponentBase
    {
    public:
        using ComponentType = ComponentT;

        Component(bool show_active_checkbox = true,
            const std::string& name = "");

    protected:
        template <typename... Args>
        bool modified_helper(bool reset, Args&... args);

        template <typename... Args>
        void render_helper(Args&... args);

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

#include "Planar/Editor/UI/Element/Component/Core/Component.tpp"
