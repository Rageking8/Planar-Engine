#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

#include <array>
#include <cfloat>
#include <string>

namespace Planar::Engine::UI::ImGui::Element::Drag
{
    PLANAR_API void drag_float(const std::string& label,
        float& value, float speed = 0.1f, float min = -FLT_MAX,
        float max = FLT_MAX, const std::string& format = "%.3f",
        int flags = 0);

    PLANAR_API void drag_float_2(const std::string& label,
        std::array<float, 2>& value, float speed = 0.1f,
        float min = -FLT_MAX, float max = FLT_MAX,
        const std::string& format = "%.3f", int flags = 0);
}
