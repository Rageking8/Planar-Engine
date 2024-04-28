#include "Planar/Engine/UI/ImGui/ImGui.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui
{
    void text(const std::string& text)
    {
        ::ImGui::Text(text.c_str());
    }
}
