#pragma once

#include "Planar/Engine/Core/ExportMacros.hpp"
#include "Planar/Engine/Math/Size2D.hpp"

#include <string>

namespace Planar::Engine::UI::ImGui
{
    void PLANAR_API text(const std::string& text);

    bool PLANAR_API button(const std::string& name,
        Planar::Engine::Math::Size2Df size = {});

    void PLANAR_API newline();
}
