#include "Planar/Editor/UI/Element/Component/CharacterController2D.hpp"
#include "Planar/Engine/UI/ImGui/Core/Size/Width.hpp"

namespace Planar::Editor::UI::Element::Component
{
    CharacterController2D::CharacterController2D() : speed("Speed",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FILL,
        0.f, 0.f, 20.f }, 125.f, true), enable_x_flip("Enable X Flip"),
        inverse_x_flip("Inverse X Flip")
    {

    }

    bool CharacterController2D::get_modified(bool reset)
    {
        return modified_helper(reset, active_checkbox, speed,
            enable_x_flip, inverse_x_flip);
    }

    void CharacterController2D::render_content()
    {
        render_with_padding(speed);
        render_with_padding(enable_x_flip);

        if (enable_x_flip.get_value())
        {
            render_with_padding(inverse_x_flip);
        }
    }

    void CharacterController2D::set_values_impl(
        ComponentType* character_controller)
    {
        active_checkbox.set_value(character_controller->get_active());
        speed.set_x(character_controller->get_speed());
        enable_x_flip.set_value(character_controller->get_enable_x_flip());
        inverse_x_flip.set_value(character_controller->get_inverse_x_flip());
    }

    void CharacterController2D::write_values_impl(
        ComponentType* character_controller)
    {
        character_controller->set_active(active_checkbox.get_value());
        character_controller->set_speed(speed.get_x());
        character_controller->set_enable_x_flip(enable_x_flip.get_value());
        character_controller->set_inverse_x_flip(inverse_x_flip.get_value());
    }
}
