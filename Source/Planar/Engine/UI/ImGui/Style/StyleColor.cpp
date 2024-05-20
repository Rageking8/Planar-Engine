#include "Planar/Engine/UI/ImGui/Style/StyleColor.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Style
{
    StyleColor::~StyleColor()
    {
        pop();
    }

    void StyleColor::set_button_background_color(
        Planar::Engine::Graphics::Color color)
    {
        ::ImGui::PushStyleColor(ImGuiCol_Button,
            { color.r, color.g, color.b, color.a });
        push_count++;
    }

    void StyleColor::set_button_hover_background_color(
        Planar::Engine::Graphics::Color color)
    {
        ::ImGui::PushStyleColor(ImGuiCol_ButtonHovered,
            { color.r, color.g, color.b, color.a });
        push_count++;
    }

    void StyleColor::set_button_active_background_color(
        Planar::Engine::Graphics::Color color)
    {
        ::ImGui::PushStyleColor(ImGuiCol_ButtonActive,
            { color.r, color.g, color.b, color.a });
        push_count++;
    }

    void StyleColor::pop()
    {
        ::ImGui::PopStyleColor(push_count);
        push_count = 0;
    }
}
