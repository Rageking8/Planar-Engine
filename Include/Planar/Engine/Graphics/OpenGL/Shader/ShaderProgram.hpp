#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Graphics/OpenGL/Core/Resource.hpp"
#include "Planar/Engine/Graphics/OpenGL/Shader/Shader.hpp"

#include "ThirdParty/glad/gl.h"

namespace Planar::Engine::Graphics::OpenGL::Shader
{
    class PLANAR_API ShaderProgram : public Core::Resource
    {
    public:
        ShaderProgram();
        ~ShaderProgram();

        void create(const VertexShader& vertex_shader,
            const FragmentShader& fragment_shader);
        void use() const;

    private:
        static void free_impl(GLuint id);
    };
}
