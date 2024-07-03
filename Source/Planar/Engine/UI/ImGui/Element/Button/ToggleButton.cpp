#include "Planar/Engine/UI/ImGui/Element/Button/ToggleButton.hpp"

namespace Planar::Engine::UI::ImGui::Element::Button
{
    ToggleButton::ToggleButton() : current{}
    {

    }

    void ToggleButton::render()
    {
        if (!states || states->empty())
        {
            Button::render();

            return;
        }

        if (current == 0)
        {
            Button::render();
        }
        else
        {
            ToggleState& current_state = (*states)[current - 1];
            render_button(current_state.label, current_state.texture);
        }

        if (is_clicked())
        {
            increment_current();
        }
    }

    void ToggleButton::add_state(const std::string& new_label,
        GLuint new_texture)
    {
        if (!states)
        {
            set(new_label, new_texture);
            states.emplace();

            return;
        }

        states->push_back({ new_label, new_texture });
    }

    unsigned ToggleButton::get_current() const
    {
        return current;
    }

    void ToggleButton::increment_current()
    {
        current = (current + 1) % (states->size() + 1);
    }
}
