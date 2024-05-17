#pragma once

#include "Planar/Engine/Core/Utils/EnumClassFlags.hpp"

PLANAR_BEGIN_ENUM_CLASS_FLAG(Planar::Engine::UI::ImGui::Window,
    ImGuiWindowFlags)
{
    NONE = 0,
    FIT_TO_WINDOW = 1 << 0,
    MINIMAL = 1 << 1,
    NO_STORE_INI = 1 << 2,
    ALWAYS_VERTICAL_SCROLLBAR = 1 << 3,
};
PLANAR_END_ENUM_CLASS_FLAG
