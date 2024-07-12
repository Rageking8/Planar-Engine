#include "Planar/Engine/UI/ImGui/Core/Size/Width.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Core::Size
{
    Width::Width(WidthMode mode, float width, float x_offset,
        float fill_width_offset) : mode{ mode }, width{ width },
        x_offset{ x_offset }, fill_width_offset{ fill_width_offset }
    {

    }

    void Width::set() const
    {
        Cursor::move_x(x_offset);

        switch (mode)
        {
        case WidthMode::DEFAULT:
            break;

        case WidthMode::FIXED:
            ::ImGui::SetNextItemWidth(width);
            break;

        case WidthMode::FILL:
            ::ImGui::SetNextItemWidth(get_content_region_avail().
                width - fill_width_offset);
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

    void Width::set_x_offset(float new_x_offset)
    {
        x_offset = new_x_offset;
    }

    void Width::set_fill_width_offset(float new_fill_width_offset)
    {
        fill_width_offset = new_fill_width_offset;
    }
}
