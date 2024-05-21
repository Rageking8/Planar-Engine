#pragma once

#include "Planar/Engine/Graphics/OpenGL/Core/Resource.hpp"
#include "Planar/Engine/Graphics/OpenGL/Shader/ShaderType.hpp"

#include "ThirdParty/glad/gl.h"

#include <string>

namespace Planar::Engine::Graphics::OpenGL::Shader
{
    template <ShaderType ShaderT>
    class Shader : public Core::Resource
    {
    public:
        Shader();
        ~Shader();

        void create(const std::string& source);

    private:
        static void free_impl(GLuint id);
    };

    using VertexShader = Shader<ShaderType::VERTEX>;
    using FragmentShader = Shader<ShaderType::FRAGMENT>;
}

#include "Planar/Engine/Graphics/OpenGL/Shader/Shader.tpp"
