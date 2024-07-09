#include "Planar/Engine/Component/SpriteRenderer.hpp"
#include "Planar/Engine/Scene/Scene.hpp"
#include "Planar/Engine/Core/Application.hpp"
#include "Planar/Engine/GameObject/GameObject.hpp"
#include "Planar/Engine/Component/Transform2D.hpp"
#include "Planar/Engine/Component/Camera2D.hpp"
#include "Planar/Engine/Graphics/OpenGL/Core/ObjectManager.hpp"
#include "Planar/Engine/Graphics/OpenGL/Shader/SpriteShader.hpp"
#include "Planar/Engine/Graphics/OpenGL/Shader/ShaderManager.hpp"
#include "Planar/Engine/Graphics/OpenGL/Render/Primitive.hpp"
#include "Planar/Engine/Graphics/OpenGL/Render/Render.hpp"

#include "ThirdParty/glad/gl.h"

#include <memory>

namespace Planar::Engine::Component
{
    SpriteRenderer::SpriteRenderer(GameObject::GameObject* parent,
        bool generate_guid) : Component(parent, generate_guid)
    {

    }

    PLANAR_DEFINE_COMPONENT_GET_SET(SpriteRenderer, std::string,
        sprite)

    void SpriteRenderer::load_impl()
    {
        set_sprite(asset.get_sprite());
    }

    void SpriteRenderer::render_impl()
    {
        std::shared_ptr<Camera2D> camera = get_active_main_camera();

        if (!camera)
        {
            return;
        }

        std::shared_ptr<Transform2D> transform = get_transform();

        Engine::Core::Application* application = get_parent()->
            get_scene()->get_application();

        application->get_shader_manager().get
            <Graphics::OpenGL::Shader::SpriteShader>("Sprite")->use(
            transform->get_model_mat(), camera->get_view_mat(),
            application->get_projection_mat());

        glActiveTexture(GL_TEXTURE0);

        application->get_object_manager().get_quad().bind();
        Graphics::OpenGL::Render::draw_arrays(
            Graphics::OpenGL::Render::Primitive::TRIANGLE_STRIP, 0, 4);
    }
}
