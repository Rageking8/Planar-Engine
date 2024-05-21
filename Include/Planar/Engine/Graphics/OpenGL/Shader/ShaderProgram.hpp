#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Core/Utils/Macros/TypeHelperMacros.hpp"
#include "Planar/Engine/Graphics/OpenGL/Shader/Shader.hpp"

#include "ThirdParty/glad/gl.h"

namespace Planar::Engine::Graphics::OpenGL::Shader
{
    class PLANAR_API ShaderProgram
    {
    public:
        ShaderProgram();
        ~ShaderProgram();

        PLANAR_DELETE_COPY_FUNCTIONS(ShaderProgram)

        void create(const VertexShader& vertex_shader,
            const FragmentShader& fragment_shader);
        void free();

        void use() const;

    private:
        GLuint id;
    };
}
