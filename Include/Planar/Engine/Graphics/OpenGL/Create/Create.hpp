#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Graphics/Image/STBImage.hpp"

#include "ThirdParty/glad/gl.h"

namespace Planar::Engine::Graphics::OpenGL::Create
{
    PLANAR_API void create_texture(GLuint* texture,
        Planar::Engine::Graphics::Image::STBImage& stb_image);
}
