#pragma once

#include "ThirdParty/glad/gl.h"

namespace Planar::Engine::Graphics::OpenGL::Texture
{
    enum class TextureMinFilter
    {
        NEAREST = GL_NEAREST,

        LINEAR = GL_LINEAR,

        NEAREST_MIPMAP_NEAREST = GL_NEAREST_MIPMAP_NEAREST,

        LINEAR_MIPMAP_NEAREST = GL_LINEAR_MIPMAP_NEAREST,

        NEAREST_MIPMAP_LINEAR = GL_NEAREST_MIPMAP_LINEAR,

        LINEAR_MIPMAP_LINEAR = GL_LINEAR_MIPMAP_LINEAR,
    };
}
