#pragma once

#include "ThirdParty/glad/gl.h"

namespace Planar::Engine::Graphics::OpenGL::Shader
{
    enum class ShaderType
    {
        VERTEX = GL_VERTEX_SHADER,

        FRAGMENT = GL_FRAGMENT_SHADER,
    };
}
