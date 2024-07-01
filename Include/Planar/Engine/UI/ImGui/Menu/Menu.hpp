#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

#include <string>

namespace Planar::Engine::UI::ImGui::Menu
{
    PLANAR_API bool menu_item(const std::string& label,
        const std::string& shortcut = "", bool selected = false,
        bool enabled = true);
}
