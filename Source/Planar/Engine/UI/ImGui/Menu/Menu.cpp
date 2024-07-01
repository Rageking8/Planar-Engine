#include "Planar/Engine/UI/ImGui/Menu/Menu.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Menu
{
    bool menu_item(const std::string& label,
        const std::string& shortcut, bool selected, bool enabled)
    {
        return ::ImGui::MenuItem(label.c_str(), shortcut.c_str(),
            selected, enabled);
    }
}
