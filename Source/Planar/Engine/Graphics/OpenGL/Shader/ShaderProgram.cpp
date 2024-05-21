#include "Planar/Engine/Graphics/OpenGL/Shader/ShaderProgram.hpp"

namespace Planar::Engine::Graphics::OpenGL::Shader
{
    ShaderProgram::ShaderProgram() : id{}
    {

    }

    ShaderProgram::~ShaderProgram()
    {
        free();
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

    void ShaderProgram::free()
    {
        glDeleteProgram(id);
        id = 0;
    }

    void ShaderProgram::use() const
    {
        glUseProgram(id);
    }
}
