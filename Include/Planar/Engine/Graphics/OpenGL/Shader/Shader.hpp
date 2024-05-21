#pragma once

#include "Planar/Engine/Core/Utils/Macros/TypeHelperMacros.hpp"
#include "Planar/Engine/Graphics/OpenGL/Shader/ShaderType.hpp"

#include "ThirdParty/glad/gl.h"

#include <string>

namespace Planar::Engine::Graphics::OpenGL::Shader
{
    template <ShaderType ShaderT>
    class Shader
    {
    public:
        Shader();
        ~Shader();

        PLANAR_DELETE_COPY_FUNCTIONS(Shader)

        void create(const std::string& source);
        void free();

        GLuint get_id() const;

    private:
        GLuint id;
    };

    using VertexShader = Shader<ShaderType::VERTEX>;
    using FragmentShader = Shader<ShaderType::FRAGMENT>;
}

#include "Planar/Engine/Graphics/OpenGL/Shader/Shader.tpp"
