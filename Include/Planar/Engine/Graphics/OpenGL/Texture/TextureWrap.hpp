#pragma once

#include "ThirdParty/glad/gl.h"

namespace Planar::Engine::Graphics::OpenGL::Texture
{
    enum class TextureWrap
    {
        CLAMP_TO_EDGE = GL_CLAMP_TO_EDGE,

        CLAMP_TO_BORDER = GL_CLAMP_TO_BORDER,

        MIRRORED_REPEAT = GL_MIRRORED_REPEAT,

        REPEAT = GL_REPEAT,

        MIRROR_CLAMP_TO_EDGE = GL_MIRROR_CLAMP_TO_EDGE,
    };
}
