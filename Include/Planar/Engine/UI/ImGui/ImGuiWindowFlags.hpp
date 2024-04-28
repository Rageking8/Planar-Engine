#pragma once

#include "Planar/Engine/Core/Utils/EnumClassFlags.hpp"

PLANAR_BEGIN_ENUM_CLASS_FLAG(Planar::Engine::UI::ImGui,
    ImGuiWindowFlags)
{
    FIT_TO_WINDOW = 1 << 0,
    MINIMAL = 1 << 1,
};
PLANAR_END_ENUM_CLASS_FLAG
