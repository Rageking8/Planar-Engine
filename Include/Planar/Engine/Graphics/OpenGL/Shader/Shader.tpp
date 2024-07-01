#include "Planar/Engine/Graphics/OpenGL/Shader/Shader.hpp"
#include "Planar/Engine/Graphics/OpenGL/Shader/ShaderFunction.hpp"

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

        id = create_shader(ShaderT);
        shader_source(id, source);
        compile_shader(id);
    }

    template <ShaderType ShaderT>
    inline void Shader<ShaderT>::free_impl(GLuint id)
    {
        delete_shader(id);
    }
}
