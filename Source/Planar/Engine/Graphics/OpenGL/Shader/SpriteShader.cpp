#include "Planar/Engine/Graphics/OpenGL/Shader/SpriteShader.hpp"
#include "Planar/Engine/Asset/LoadAssetMacros.hpp"

PLANAR_LOAD_STD_STRING_ASSET(Engine::Graphics::Shader, SpriteVert)
PLANAR_LOAD_STD_STRING_ASSET(Engine::Graphics::Shader, SpriteFrag)

namespace Planar::Engine::Graphics::OpenGL::Shader
{
    SpriteShader::SpriteShader()
    {
        create(Asset::Engine::Graphics::Shader::SpriteVert,
            Asset::Engine::Graphics::Shader::SpriteFrag);
    }

    void SpriteShader::use(const glm::mat4& model,
        const glm::mat4& view, const glm::mat4& projection,
        const glm::vec2& tile_factor)
    {
        ShaderProgram::use();

        set_mat4(0, model);
        set_mat4(1, view);
        set_mat4(2, projection);
        set_vec2(3, tile_factor);
    }
}
