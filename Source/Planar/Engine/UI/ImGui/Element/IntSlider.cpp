#include "Planar/Engine/UI/ImGui/Element/IntSlider.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/Core/Utils/Checks/Assert.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Element
{
    IntSlider::IntSlider(int value, int min_value, int max_value,
        const std::string& label, float width) : value{ value },
        min_value{ min_value }, max_value{ max_value },
        width{ width }
    {
        PLANAR_ASSERT(min_value <= max_value,
            "`min_value` must be less than or equal to `max_value`");
        PLANAR_ASSERT(min_value <= value && value <= max_value,
            "`value` must be within range [`min_value`, `max_value`]");

        this->label = label.empty() ? generate_unique_label() :
            "##" + label;
        set_render_label(!label.empty());
    }

    void IntSlider::render()
    {
        if (render_label)
        {
            ImGui::text(label.substr(2), true);
            ImGui::same_line();
        }

        if (width != 0.f)
        {
            ::ImGui::SetNextItemWidth(width);
        }

        ::ImGui::SliderInt(label.c_str(), &value, min_value,
            max_value, "%d", ImGuiSliderFlags_AlwaysClamp |
            ImGuiSliderFlags_NoInput);
    }

    int IntSlider::get_value() const
    {
        return value;
    }

    void IntSlider::set_render_label(bool new_render_label)
    {
        render_label = new_render_label;
    }

    void IntSlider::set_min_value(int new_min_value)
    {
        PLANAR_ASSERT(new_min_value <= max_value,
            "`new_min_value` must be less than or equal to `max_value`");

        min_value = new_min_value;
    }

    void IntSlider::set_max_value(int new_max_value)
    {
        PLANAR_ASSERT(new_max_value >= min_value,
            "`new_max_value` must be more than or equal to `min_value`");

        max_value = new_max_value;
    }

    void IntSlider::set_width(float new_width)
    {
        PLANAR_ASSERT(new_width >= 0.f,
            "`new_width` must be more than or equal to 0");

        width = new_width;
    }
}
