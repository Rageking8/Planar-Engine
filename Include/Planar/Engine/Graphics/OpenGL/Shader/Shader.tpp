#include "Planar/Engine/Graphics/OpenGL/Shader/Shader.hpp"
#include "Planar/Engine/Graphics/OpenGL/Wrapper/Shader/Shader.hpp"

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

        id = Wrapper::Shader::create_shader(ShaderT);
        Wrapper::Shader::shader_source(id, source);
        Wrapper::Shader::compile_shader(id);
    }

    template <ShaderType ShaderT>
    inline void Shader<ShaderT>::free_impl(GLuint id)
    {
        Wrapper::Shader::delete_shader(id);
    }
}
