#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Graphics/OpenGL/Shader/ShaderType.hpp"

#include "ThirdParty/glad/gl.h"

#include <string>

namespace Planar::Engine::Graphics::OpenGL::Wrapper::Shader
{
    PLANAR_API GLuint create_shader(
        OpenGL::Shader::ShaderType shader_type);

    PLANAR_API void shader_source(GLuint id,
        const std::string& source);

    PLANAR_API void compile_shader(GLuint id);

    PLANAR_API void delete_shader(GLuint id);
}
