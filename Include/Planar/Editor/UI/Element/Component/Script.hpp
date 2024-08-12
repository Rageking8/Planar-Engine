#pragma once

#include "Planar/Editor/UI/Element/Component/Core/Component.hpp"
#include "Planar/Engine/Component/Script.hpp"

namespace Planar::Editor::UI::Element::Component
{
    class Script : public Core::Component<Engine::Component::Script>
    {
    public:
        Script();

        virtual bool get_modified(bool reset = true) override;

    private:
        virtual void render_content() override;

        virtual void set_values_impl(ComponentType* script) override;
        virtual void write_values_impl(ComponentType* script) override;
    };
}
