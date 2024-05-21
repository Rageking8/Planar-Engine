#include "Planar/Engine/Graphics/OpenGL/Shader/Shader.hpp"

namespace Planar::Engine::Graphics::OpenGL::Shader
{
    template <ShaderType ShaderT>
    inline Shader<ShaderT>::Shader() : Resource(free_impl)
    {

    }

    template <ShaderType ShaderT>
    inline Shader<ShaderT>::~Shader()
    {

    }

    template <ShaderType ShaderT>
    inline void Shader<ShaderT>::create(const std::string& source)
    {
        free();

        id = glCreateShader((GLenum)ShaderT);

        const char* source_c_str = source.c_str();
        glShaderSource(id, 1, &source_c_str, nullptr);

        glCompileShader(id);
    }

    template <ShaderType ShaderT>
    inline void Shader<ShaderT>::free_impl(GLuint id)
    {
        glDeleteShader(id);
    }
}
