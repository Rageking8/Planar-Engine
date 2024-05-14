#include "Planar/Engine/UI/ImGui/ImGuiGroup.hpp"
#include "Planar/Engine/UI/ImGui/Macros/WrapperMacros.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui
{
    PLANAR_DEFINE_IMGUI_WRAPPER(ImGuiGroup, BeginGroup, EndGroup)
}
