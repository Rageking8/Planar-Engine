#include "Planar/Engine/UI/ImGui/Element/Button/Button.hpp"
#include "Planar/Engine/UI/ImGui/Element/Button/ButtonFunction.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"

namespace Planar::Engine::UI::ImGui::Element::Button
{
    Button::Button(const std::string& label,
        Math::Size2Df size, GLuint texture) : label{ label },
        size{ size }, texture{ texture }, clicked{},
        left_double_clicked{}
    {

    }

    void Button::set(const std::string& new_label,
        Math::Size2Df new_size, GLuint new_texture)
    {
        label = new_label;
        size = new_size;
        texture = new_texture;
    }

    void Button::render()
    {
        if (texture)
        {
            clicked |= button(label, texture, size);
        }
        else
        {
            clicked |= button(label, size);
        }

        left_double_clicked |= is_item_hovered() &&
            is_left_mouse_double_clicked();
    }

    bool Button::is_clicked()
    {
        bool result = clicked;
        clicked = false;

        return result;
    }

    bool Button::is_left_double_clicked()
    {
        bool result = left_double_clicked;
        left_double_clicked = false;

        return result;
    }
}
