#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

#include "ThirdParty/glad/gl.h"

#include <cstddef>
#include <filesystem>

namespace Planar::Engine::Graphics::Load
{
    PLANAR_API GLuint load_image(
        const std::filesystem::path& image_path);

    PLANAR_API GLuint load_image(const unsigned char* buffer,
        std::size_t length);
}
