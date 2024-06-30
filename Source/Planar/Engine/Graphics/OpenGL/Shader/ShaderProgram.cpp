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

    void ShaderProgram::set_mat4(GLint location, const glm::mat4& value)
    {
        glUniformMatrix4fv(location, 1, GL_FALSE, &value[0][0]);
    }

    void ShaderProgram::free_impl(GLuint id)
    {
        glDeleteProgram(id);
    }
}
