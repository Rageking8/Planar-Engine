#include "Planar/Editor/UI/Element/Component/CharacterController2D.hpp"

namespace Planar::Editor::UI::Element::Component
{
    CharacterController2D::CharacterController2D()
    {

    }

    bool CharacterController2D::get_modified(bool reset)
    {
        return modified_helper(reset, active_checkbox);
    }

    void CharacterController2D::render_content()
    {

    }

    void CharacterController2D::set_values_impl(
        ComponentType* character_controller)
    {

    }

    void CharacterController2D::write_values_impl(
        ComponentType* character_controller)
    {

    }
}
