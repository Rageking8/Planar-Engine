#include "Planar/Engine/UI/ImGui/Element/ProgressBar.hpp"
#include "Planar/Engine/UI/ImGui/Style/StyleVar.hpp"
#include "Planar/Engine/UI/ImGui/Style/StyleColor.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/Core/Utils/Checks/Assert.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Element
{
    ProgressBar::ProgressBar(unsigned value, unsigned max,
        Math::Size2Df size, Graphics::Color foreground_color,
        Graphics::Color background_color) : value{ value },
        max{ max }, size{ size },
        foreground_color{ foreground_color },
        background_color{ background_color }
    {

    }

    void ProgressBar::render()
    {
        Style::StyleColor style_color;
        style_color.set_plot_histogram_color(foreground_color);
        style_color.set_frame_bg_color(background_color);

        Style::StyleVar style_var;
        style_var.set_frame_padding(
            { 0.f, (size.height - get_font_size()) * 0.5f });

        ::ImGui::ProgressBar(static_cast<float>(value) / max,
            { size.width, 0.f }, "");
    }

    unsigned ProgressBar::get_value() const
    {
        return value;
    }

    unsigned ProgressBar::get_max() const
    {
        return max;
    }

    Math::Size2Df ProgressBar::get_size() const
    {
        return size;
    }

    float ProgressBar::get_width() const
    {
        return size.width;
    }

    float ProgressBar::get_height() const
    {
        return size.height;
    }

    Graphics::Color ProgressBar::get_foreground_color() const
    {
        return foreground_color;
    }

    Graphics::Color ProgressBar::get_background_color() const
    {
        return background_color;
    }

    void ProgressBar::increment(unsigned delta)
    {
        set_value(value + delta);
    }

    void ProgressBar::set_value(unsigned new_value)
    {
        PLANAR_ASSERT(new_value <= max,
            "`new_value` must be less than or equal to `max`");

        value = new_value;
    }

    void ProgressBar::set_max(unsigned new_max)
    {
        PLANAR_ASSERT(new_max >= value,
            "`new_max` must be more than or equal to `value`");

        max = new_max;
    }

    void ProgressBar::set_size(Math::Size2Df new_size)
    {
        size = new_size;
    }

    void ProgressBar::set_width(float new_width)
    {
        size = { new_width, size.height };
    }

    void ProgressBar::set_height(float new_height)
    {
        size = { size.width, new_height };
    }

    void ProgressBar::set_foreground_color(
        Graphics::Color new_foreground_color)
    {
        foreground_color = new_foreground_color;
    }

    void ProgressBar::set_background_color(
        Graphics::Color new_background_color)
    {
        background_color = new_background_color;
    }
}
