#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Math/Size2D.hpp"

#include "ThirdParty/glad/gl.h"

#include <string>

namespace Planar::Engine::UI::ImGui::Element::Button
{
    PLANAR_API bool button(const std::string& name,
        Math::Size2Df size = {});

    PLANAR_API bool button(const std::string& name,
        GLuint texture, Math::Size2Df size);
}
