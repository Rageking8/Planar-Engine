#include "Planar/Engine/UI/ImGui/Element/Button.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"

namespace Planar::Engine::UI::ImGui::Element
{
    Button::Button(const std::string& label,
        Planar::Engine::Math::Size2Df size, GLuint texture) :
        label{ label }, size{ size }, texture{ texture }, clicked{},
        left_double_clicked{}
    {

    }

    void Button::set(const std::string& new_label,
        Planar::Engine::Math::Size2Df new_size, GLuint new_texture)
    {
        label = new_label;
        size = new_size;
        texture = new_texture;
    }

    void Button::render()
    {
        if (texture)
        {
            clicked |= Planar::Engine::UI::ImGui::button(
                label, texture, size);
        }
        else
        {
            clicked |= Planar::Engine::UI::ImGui::button(
                label, size);
        }

        left_double_clicked |=
            Planar::Engine::UI::ImGui::is_item_hovered() &&
            Planar::Engine::UI::ImGui::is_left_mouse_double_clicked();
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
