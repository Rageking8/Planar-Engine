#include "Planar/Engine/UI/ImGui/ImGuiGroup.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui
{
    ImGuiGroup::ImGuiGroup()
    {
        ::ImGui::BeginGroup();
    }

    ImGuiGroup::~ImGuiGroup()
    {
        ::ImGui::EndGroup();
    }
}
