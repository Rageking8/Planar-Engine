#include "Planar/Engine/UI/ImGui/Core/Size/Width.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Core::Size
{
    Width::Width(WidthMode mode, float width) :
        mode{ mode }, width{ width }
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
            ::ImGui::SetNextItemWidth(
                get_content_region_avail().width);
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
}
