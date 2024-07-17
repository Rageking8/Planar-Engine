#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Graphics/OpenGL/Shader/ShaderProgram.hpp"

#include "ThirdParty/glm/fwd.hpp"

namespace Planar::Engine::Graphics::OpenGL::Shader
{
    class PLANAR_API SpriteShader : public ShaderProgram
    {
    public:
        SpriteShader();

        void use(const glm::mat4& model, const glm::mat4& view,
            const glm::mat4& projection, const glm::vec2& tile_factor);
    };
}
