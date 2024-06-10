#include "Planar/Engine/UI/ImGui/Style/StyleColor.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Style
{
    StyleColor::~StyleColor()
    {
        pop();
    }

    void StyleColor::set_frame_bg_color(
        Graphics::Color color)
    {
        push_style_color(ImGuiCol_FrameBg, color);
    }

    void StyleColor::set_plot_histogram_color(
        Graphics::Color color)
    {
        push_style_color(ImGuiCol_PlotHistogram, color);
    }

    void StyleColor::set_button_background_color(
        Graphics::Color color)
    {
        push_style_color(ImGuiCol_Button, color);
    }

    void StyleColor::set_button_hover_background_color(
        Graphics::Color color)
    {
        push_style_color(ImGuiCol_ButtonHovered, color);
    }

    void StyleColor::set_button_active_background_color(
        Graphics::Color color)
    {
        push_style_color(ImGuiCol_ButtonActive, color);
    }

    void StyleColor::pop()
    {
        ::ImGui::PopStyleColor(push_count);
        push_count = 0;
    }

    void StyleColor::push_style_color(int type, Graphics::Color color)
    {
        ::ImGui::PushStyleColor(type,
            { color.r, color.g, color.b, color.a });
        push_count++;
    }
}
