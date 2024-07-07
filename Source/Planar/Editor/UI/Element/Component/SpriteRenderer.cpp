#include "Planar/Editor/UI/Element/Component/SpriteRenderer.hpp"

namespace Planar::Editor::UI::Element::Component
{
    SpriteRenderer::SpriteRenderer()
    {

    }

    bool SpriteRenderer::get_modified(bool reset)
    {
        bool active_modified = active_checkbox.get_modified(reset);

        return active_modified;
    }

    void SpriteRenderer::render_content()
    {

    }

    void SpriteRenderer::set_values_impl(ComponentType* sprite_renderer)
    {
        active_checkbox.set_value(sprite_renderer->get_active());
    }

    void SpriteRenderer::write_values_impl(ComponentType* sprite_renderer)
    {
        sprite_renderer->set_active(active_checkbox.get_value());
    }
}
