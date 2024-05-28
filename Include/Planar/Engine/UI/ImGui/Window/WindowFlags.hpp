#pragma once

#include "Planar/Engine/Core/Utils/EnumClass/EnumClassFlags.hpp"

PLANAR_BEGIN_ENUM_CLASS_FLAG(Planar::Engine::UI::ImGui::Window,
    WindowFlags)
{
    NONE = 0,
    FIT_TO_WINDOW = 1 << 0,
    MINIMAL = 1 << 1,
    NO_STORE_INI = 1 << 2,
    ALWAYS_VERTICAL_SCROLLBAR = 1 << 3,
    MENU_BAR = 1 << 4,
    HORIZONTAL_SCROLLBAR = 1 << 5,
    VIEWPORT_CENTER = 1 << 6,
};
PLANAR_END_ENUM_CLASS_FLAG
