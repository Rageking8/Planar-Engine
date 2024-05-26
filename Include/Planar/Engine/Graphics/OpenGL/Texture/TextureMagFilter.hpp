#pragma once

#include "ThirdParty/glad/gl.h"

namespace Planar::Engine::Graphics::OpenGL::Texture
{
    enum class TextureMagFilter
    {
        NEAREST = GL_NEAREST,

        LINEAR = GL_LINEAR,
    };
}
