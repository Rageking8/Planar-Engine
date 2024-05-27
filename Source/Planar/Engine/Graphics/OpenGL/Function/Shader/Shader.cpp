#include "Planar/Engine/Graphics/OpenGL/Function/Shader/Shader.hpp"

namespace Planar::Engine::Graphics::OpenGL::Function::Shader
{
    GLuint create_shader(OpenGL::Shader::ShaderType shader_type)
    {
        return glCreateShader((GLenum)shader_type);
    }

    void shader_source(GLuint id, const std::string& source)
    {
        const char* source_c_str = source.c_str();
        glShaderSource(id, 1, &source_c_str, nullptr);
    }

    void compile_shader(GLuint id)
    {
        glCompileShader(id);
    }

    void delete_shader(GLuint id)
    {
        glDeleteShader(id);
    }
}
