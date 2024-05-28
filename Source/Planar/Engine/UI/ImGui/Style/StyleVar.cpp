#include "Planar/Engine/UI/ImGui/Style/StyleVar.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Style
{
    StyleVar::~StyleVar()
    {
        pop();
    }

    void StyleVar::set_frame_padding(Math::Size2Df padding)
    {
        ::ImGui::PushStyleVar(ImGuiStyleVar_FramePadding,
            { padding.width, padding.height });
        push_count++;
    }

    void StyleVar::set_window_padding(Math::Size2Df padding)
    {
        ::ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding,
            { padding.width, padding.height });
        push_count++;
    }

    void StyleVar::pop()
    {
        ::ImGui::PopStyleVar(push_count);
        push_count = 0;
    }
}
