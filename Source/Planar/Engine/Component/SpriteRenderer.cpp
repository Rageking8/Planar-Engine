#include "Planar/Engine/Component/SpriteRenderer.hpp"
#include "Planar/Engine/Scene/Scene.hpp"
#include "Planar/Engine/Core/Application.hpp"
#include "Planar/Engine/Core/Sprite/Sprite.hpp"
#include "Planar/Engine/GameObject/GameObject.hpp"
#include "Planar/Engine/Component/Transform2D.hpp"
#include "Planar/Engine/Component/Camera2D.hpp"
#include "Planar/Engine/Graphics/OpenGL/Core/ObjectManager.hpp"
#include "Planar/Engine/Graphics/OpenGL/Shader/SpriteShader.hpp"
#include "Planar/Engine/Graphics/OpenGL/Shader/ShaderManager.hpp"
#include "Planar/Engine/Graphics/OpenGL/Render/Primitive.hpp"
#include "Planar/Engine/Graphics/OpenGL/Render/Render.hpp"

#include "ThirdParty/glad/gl.h"
#include "ThirdParty/glm/gtc/matrix_transform.hpp"

#include <memory>

namespace Planar::Engine::Component
{
    SpriteRenderer::SpriteRenderer(GameObject::GameObject* parent,
        bool generate_guid) : Component(parent, generate_guid),
        flip_x{}, flip_y{}, tile_factor{ 1.f }
    {

    }

    PLANAR_DEFINE_COMPONENT_GET_SET(SpriteRenderer, std::string,
        sprite)
    PLANAR_DEFINE_COMPONENT_GET_SET(SpriteRenderer, bool, flip_x)
    PLANAR_DEFINE_COMPONENT_GET_SET(SpriteRenderer, bool, flip_y)
    PLANAR_DEFINE_COMPONENT_GET_SET(SpriteRenderer, Math::Size2Df,
        tile_factor)

    glm::mat4 SpriteRenderer::calc_model_mat() const
    {
        std::shared_ptr<Transform2D> transform = get_transform();

        glm::mat4 model = transform->get_model_mat();
        model = glm::scale(model,
            { flip_x ? -1.f : 1.f, flip_y ? -1.f : 1.f, 1.f });

        return model;
    }

    void SpriteRenderer::load_impl()
    {
        set_sprite(asset.get_sprite());
        set_flip_x(asset.get_flip_x());
        set_flip_y(asset.get_flip_y());
        set_tile_factor(asset.get_tile_factor());
    }

    void SpriteRenderer::render_impl()
    {
        if (sprite.empty())
        {
            return;
        }

        std::shared_ptr<Camera2D> camera = get_active_main_camera();

        if (!camera)
        {
            return;
        }

        Engine::Core::Application* application = get_parent()->
            get_scene()->get_application();

        application->get_shader_manager().get
            <Graphics::OpenGL::Shader::SpriteShader>("Sprite")->use(
            calc_model_mat(), camera->get_view_mat(),
            camera->get_projection_mat(),
            { tile_factor.first, tile_factor.second });

        glActiveTexture(GL_TEXTURE0);
        application->get_asset_database()->get_owning_asset
            <Engine::Core::Sprite::Sprite>(sprite)->get_texture().bind();

        application->get_object_manager().get_quad().bind();
        Graphics::OpenGL::Render::draw_arrays(
            Graphics::OpenGL::Render::Primitive::TRIANGLE_STRIP, 0, 4);
    }
}
