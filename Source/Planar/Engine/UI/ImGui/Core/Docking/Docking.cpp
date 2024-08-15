#include "Planar/Engine/UI/ImGui/Core/Docking/Docking.hpp"
#include "Planar/Engine/UI/ImGui/Style/StyleVar.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Core::Docking
{
    void dock_space_over_viewport(float tab_bar_overline_size)
    {
        Style::StyleVar style_var;
        style_var.set_tab_bar_overline_size(tab_bar_overline_size);

        ::ImGui::DockSpaceOverViewport(0, ::ImGui::GetMainViewport());
    }
}
