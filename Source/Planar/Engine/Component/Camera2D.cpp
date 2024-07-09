#include "Planar/Engine/Component/Camera2D.hpp"
#include "Planar/Engine/Component/Transform2D.hpp"
#include "Planar/Engine/Core/Application.hpp"
#include "Planar/Engine/Math/Size2D.hpp"

#include "ThirdParty/glm/vec3.hpp"
#include "ThirdParty/glm/gtc/matrix_transform.hpp"

#include <memory>

namespace Planar::Engine::Component
{
    Camera2D::Camera2D(GameObject::GameObject* parent,
        bool generate_guid) : Component(parent, generate_guid)
    {

    }

    glm::mat4 Camera2D::get_view_mat() const
    {
        std::shared_ptr<Transform2D> transform = get_transform();
        const glm::vec3 position{ transform->get_position().x,
            transform->get_position().y, 0.f };

        return glm::lookAt(position, position +
            glm::vec3(0.f, 0.f, -1.f), { 0.f, 1.f, 0.f });
    }

    glm::mat4 Camera2D::get_projection_mat() const
    {
        const Math::Size2Df framebuffer_size =
            static_cast<Math::Size2Df>(get_parent()->
            get_scene()->get_application()->
            get_game_framebuffer_size());

        return glm::ortho(0.f, framebuffer_size.width,
            framebuffer_size.height, 0.f, -1.f, 1.f);
    }

    void Camera2D::load_impl()
    {

    }
}
