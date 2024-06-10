#include "Planar/Engine/UI/ImGui/Core/Docking/Docking.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Core::Docking
{
    void dock_space_over_viewport()
    {
        ::ImGui::DockSpaceOverViewport(::ImGui::GetMainViewport());
    }
}
