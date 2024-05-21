#include "Planar/Engine/Graphics/OpenGL/Shader/Shader.hpp"

namespace Planar::Engine::Graphics::OpenGL::Shader
{
    template <ShaderType ShaderT>
    inline Shader<ShaderT>::Shader() : id{}
    {

    }

    template <ShaderType ShaderT>
    inline Shader<ShaderT>::~Shader()
    {
        free();
    }

    template <ShaderType ShaderT>
    void Shader<ShaderT>::create(const std::string& source)
    {
        free();

        id = glCreateShader((GLenum)ShaderT);

        const char* source_c_str = source.c_str();
        glShaderSource(id, 1, &source_c_str, nullptr);

        glCompileShader(id);
    }

    template <ShaderType ShaderT>
    void Shader<ShaderT>::free()
    {
        glDeleteShader(id);
        id = 0;
    }

    template <ShaderType ShaderT>
    GLuint Shader<ShaderT>::get_id() const
    {
        return id;
    }
}
