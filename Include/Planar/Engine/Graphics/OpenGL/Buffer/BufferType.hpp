#pragma once

#include "ThirdParty/glad/gl.h"

namespace Planar::Engine::Graphics::OpenGL::Buffer
{
    enum class BufferType
    {
        ARRAY = GL_ARRAY_BUFFER,

        ELEMENT_ARRAY = GL_ELEMENT_ARRAY_BUFFER,
    };
}
