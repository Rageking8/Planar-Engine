#pragma once

#include "Planar/Engine/Core/ExportMacros.hpp"
#include "Planar/Engine/Math/Size2D.hpp"

#include <string>

namespace Planar::Engine::UI::ImGui
{
    PLANAR_API void reset_style();

    PLANAR_API void scale_ui(int factor);

    PLANAR_API std::string generate_unique_label();

    PLANAR_API void text(const std::string& text);

    PLANAR_API bool button(const std::string& name,
        Planar::Engine::Math::Size2Df size = {});

    PLANAR_API void newline();
}
