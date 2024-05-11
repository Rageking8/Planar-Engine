#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

#include "ThirdParty/glad/gl.h"

#include <filesystem>

namespace Planar::Engine::Graphics::Load
{
    PLANAR_API GLuint load_image(
        const std::filesystem::path& image_path);
}
