#pragma once

#include "Planar/Editor/UI/Element/Component/Core/Component.hpp"
#include "Planar/Engine/Component/SpriteRenderer.hpp"

namespace Planar::Editor::UI::Element::Component
{
    class SpriteRenderer :
        public Core::Component<Engine::Component::SpriteRenderer>
    {
    public:
        SpriteRenderer();

        virtual bool get_modified(bool reset = true) override;

    private:
        virtual void render_content() override;

        virtual void set_values_impl(ComponentType* sprite_renderer)
            override;
        virtual void write_values_impl(ComponentType* sprite_renderer)
            override;
    };
}
