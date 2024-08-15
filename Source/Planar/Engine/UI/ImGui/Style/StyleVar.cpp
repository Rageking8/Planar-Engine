#include "Planar/Engine/UI/ImGui/Style/StyleVar.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Style
{
    StyleVar::~StyleVar()
    {
        pop();
    }

    void StyleVar::set_indent_spacing(float indent_spacing)
    {
        push_style_var(ImGuiStyleVar_IndentSpacing, indent_spacing);
    }

    void StyleVar::set_item_spacing(Math::Size2Df item_spacing)
    {
        push_style_var(ImGuiStyleVar_ItemSpacing, item_spacing);
    }

    void StyleVar::set_frame_padding(Math::Size2Df padding)
    {
        push_style_var(ImGuiStyleVar_FramePadding, padding);
    }

    void StyleVar::set_window_padding(Math::Size2Df padding)
    {
        push_style_var(ImGuiStyleVar_WindowPadding, padding);
    }

    void StyleVar::set_min_window_size(Math::Size2Df min_window_size)
    {
        push_style_var(ImGuiStyleVar_WindowMinSize, min_window_size);
    }

    void StyleVar::set_tab_bar_overline_size(float overline_size)
    {
        push_style_var(ImGuiStyleVar_TabBarOverlineSize, overline_size);
    }

    void StyleVar::pop()
    {
        ::ImGui::PopStyleVar(push_count);
        push_count = 0;
    }

    void StyleVar::push_style_var(int type, float value)
    {
        ::ImGui::PushStyleVar(type, value);
        push_count++;
    }

    void StyleVar::push_style_var(int type, Math::Size2Df value)
    {
        ::ImGui::PushStyleVar(type, { value.width, value.height });
        push_count++;
    }
}
