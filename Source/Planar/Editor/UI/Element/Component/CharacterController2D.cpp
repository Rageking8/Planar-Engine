#include "Planar/Editor/UI/Element/Component/CharacterController2D.hpp"
#include "Planar/Engine/UI/ImGui/Core/Size/Width.hpp"

namespace Planar::Editor::UI::Element::Component
{
    CharacterController2D::CharacterController2D() : speed("Speed",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FILL,
        0.f, 0.f, 20.f }, 125.f, true)
    {

    }

    bool CharacterController2D::get_modified(bool reset)
    {
        return modified_helper(reset, active_checkbox, speed);
    }

    void CharacterController2D::render_content()
    {
        speed.render();
    }

    void CharacterController2D::set_values_impl(
        ComponentType* character_controller)
    {
        active_checkbox.set_value(character_controller->get_active());
        speed.set_x(character_controller->get_speed());
    }

    void CharacterController2D::write_values_impl(
        ComponentType* character_controller)
    {
        character_controller->set_active(active_checkbox.get_value());
        character_controller->set_speed(speed.get_x());
    }
}
