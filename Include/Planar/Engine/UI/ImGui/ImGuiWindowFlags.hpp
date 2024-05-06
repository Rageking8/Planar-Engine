#pragma once

#include "Planar/Engine/Core/Utils/EnumClassFlags.hpp"

PLANAR_BEGIN_ENUM_CLASS_FLAG(Planar::Engine::UI::ImGui,
    ImGuiWindowFlags)
{
    NONE = 0,
    FIT_TO_WINDOW = 1 << 0,
    MINIMAL = 1 << 1,
    NO_STORE_INI = 1 << 2,
};
PLANAR_END_ENUM_CLASS_FLAG
