#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

#include <cstddef>

namespace Planar::Engine::UI::ImGui::Font
{
    PLANAR_API void load_font(const unsigned char* buffer,
        std::size_t buffer_size, float font_size);
}
