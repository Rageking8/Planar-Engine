#include "Planar/Engine/Graphics/OpenGL/Shader/ShaderProgram.hpp"

namespace Planar::Engine::Graphics::OpenGL::Shader
{
    ShaderProgram::ShaderProgram() : Resource(free_impl)
    {

    }

    ShaderProgram::~ShaderProgram()
    {

    }

    void ShaderProgram::create(const VertexShader& vertex_shader,
        const FragmentShader& fragment_shader)
    {
        free();

        id = glCreateProgram();
        glAttachShader(id, vertex_shader.get_id());
        glAttachShader(id, fragment_shader.get_id());
        glLinkProgram(id);
    }

    void ShaderProgram::use() const
    {
        glUseProgram(id);
    }

    void ShaderProgram::free_impl(GLuint id)
    {
        glDeleteProgram(id);
    }
}
