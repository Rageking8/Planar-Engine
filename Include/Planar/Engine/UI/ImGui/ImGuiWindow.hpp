#pragma once

#include "Planar/Engine/Core/ExportMacros.hpp"
#include "Planar/Engine/Core/Utils/EnumClassFlags.hpp"

#include <string>

PLANAR_BEGIN_ENUM_CLASS_FLAG(Planar::Engine::UI::ImGui,
    ImGuiWindowFlags)
{
    FIT_TO_WINDOW = 1 << 0,
    MINIMAL = 1 << 1,
};
PLANAR_END_ENUM_CLASS_FLAG

namespace Planar::Engine::UI::ImGui
{
    class PLANAR_API ImGuiWindow
    {
    public:
        ImGuiWindow(const std::string& name, ImGuiWindowFlags flags);
        ~ImGuiWindow();
    };
}
