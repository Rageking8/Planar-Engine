#include "Planar/Engine/UI/ImGui/Core/Size/Width.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Core::Size
{
    Width::Width(WidthMode mode, float width, float fill_offset_left,
        float fill_offset_right) : mode{ mode }, width{ width },
        fill_offset_left{ fill_offset_left },
        fill_offset_right{ fill_offset_right }
    {

    }

    void Width::set() const
    {
        switch (mode)
        {
        case WidthMode::DEFAULT:
            break;

        case WidthMode::FIXED:
            ::ImGui::SetNextItemWidth(width);
            break;

        case WidthMode::FILL:
            Cursor::move_x(fill_offset_left);
            ::ImGui::SetNextItemWidth(get_content_region_avail().
                width - fill_offset_right);
            break;
        }
    }

    void Width::set_mode(WidthMode new_mode)
    {
        mode = new_mode;
    }

    void Width::set_width(float new_width)
    {
        width = new_width;
    }

    void Width::set_fill_offset_left(float new_fill_offset_left)
    {
        fill_offset_left = new_fill_offset_left;
    }

    void Width::set_fill_offset_right(float new_fill_offset_right)
    {
        fill_offset_right = new_fill_offset_right;
    }
}
