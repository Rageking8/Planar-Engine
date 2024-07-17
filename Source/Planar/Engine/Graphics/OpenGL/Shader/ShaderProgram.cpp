#include "Planar/Engine/Graphics/OpenGL/Shader/ShaderProgram.hpp"

#include "ThirdParty/glm/vec2.hpp"
#include "ThirdParty/glm/mat4x4.hpp"

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

    void ShaderProgram::set_vec2(
        GLint location, const glm::vec2& value) const
    {
        glUniform2f(location, value.x, value.y);
    }

    void ShaderProgram::set_mat4(
        GLint location, const glm::mat4& value) const
    {
        glUniformMatrix4fv(location, 1, GL_FALSE, &value[0][0]);
    }

    void ShaderProgram::free_impl(GLuint id)
    {
        glDeleteProgram(id);
    }
}
