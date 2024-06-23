#include "Planar/Engine/UI/ImGui/Core/Size/Width.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Core::Size
{
    Width::Width(WidthMode mode, float width, float fill_offset) :
        mode{ mode }, width{ width }, fill_offset{ fill_offset }
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
            Cursor::move_x(fill_offset);
            ::ImGui::SetNextItemWidth(get_content_region_avail().
                width - fill_offset);
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

    void Width::set_fill_offset(float new_fill_offset)
    {
        fill_offset = new_fill_offset;
    }
}
