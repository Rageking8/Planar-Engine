#include "Planar/Engine/Graphics/OpenGL/Shader/Shader.hpp"
#include "Planar/Engine/Graphics/OpenGL/Function/Shader/ShaderFunction.hpp"

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

        id = Function::Shader::create_shader(ShaderT);
        Function::Shader::shader_source(id, source);
        Function::Shader::compile_shader(id);
    }

    template <ShaderType ShaderT>
    inline void Shader<ShaderT>::free_impl(GLuint id)
    {
        Function::Shader::delete_shader(id);
    }
}
