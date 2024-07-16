#include "Planar/Editor/UI/Element/Component/Transform2D.hpp"

namespace Planar::Editor::UI::Element::Component
{
    Transform2D::Transform2D() : Component(false), position("Position",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FILL,
        0.f, 0.f, 20.f }, 100.f, true), rotation("Rotation",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FILL,
        0.f, 0.f, 20.f }, 100.f, true), scale("Scale",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FILL,
        0.f, 0.f, 20.f }, 100.f, true)
    {

    }

    bool Transform2D::get_modified(bool reset)
    {
        return modified_helper(reset, position, rotation, scale);
    }

    void Transform2D::render_content()
    {
        render_with_padding(position);
        render_with_padding(rotation);
        render_with_padding(scale);
    }

    void Transform2D::set_values_impl(ComponentType* transform)
    {
        position.set_value(transform->get_position().get_array());
        rotation.set_x(transform->get_rotation());
        scale.set_value(transform->get_scale().get_array());
    }

    void Transform2D::write_values_impl(ComponentType* transform)
    {
        transform->set_position(position.get_value());
        transform->set_rotation(rotation.get_x());
        transform->set_scale(scale.get_value());
    }
}
