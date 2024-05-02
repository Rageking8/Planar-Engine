#pragma once

#include "Planar/Engine/Core/ExportMacros.hpp"
#include "Planar/Engine/Math/Size2D.hpp"

#include <string>

namespace Planar::Engine::UI::ImGui
{
    PLANAR_API void text(const std::string& text);

    PLANAR_API bool button(const std::string& name,
        Planar::Engine::Math::Size2Df size = {});

    PLANAR_API void newline();
}
