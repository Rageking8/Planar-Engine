#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Graphics/OpenGL/Core/Resource.hpp"
#include "Planar/Engine/Graphics/OpenGL/Shader/Shader.hpp"

#include "ThirdParty/glad/gl.h"
#include "ThirdParty/glm/fwd.hpp"

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

        void set_vec2(GLint location, const glm::vec2& value) const;
        void set_mat4(GLint location, const glm::mat4& value) const;

    private:
        static void free_impl(GLuint id);
    };
}
