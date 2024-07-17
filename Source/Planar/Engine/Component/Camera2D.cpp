#include "Planar/Engine/Component/Camera2D.hpp"
#include "Planar/Engine/Component/Transform2D.hpp"
#include "Planar/Engine/Core/Application.hpp"
#include "Planar/Engine/Math/MatrixTransform.hpp"

#include "ThirdParty/glm/mat4x4.hpp"

#include <memory>

namespace Planar::Engine::Component
{
    Camera2D::Camera2D(GameObject::GameObject* parent,
        bool generate_guid) : Component(parent, generate_guid),
        pixel_scale{ 100.f }
    {

    }

    PLANAR_DEFINE_COMPONENT_GET_SET(Camera2D, float, pixel_scale)

    glm::mat4 Camera2D::get_view_mat() const
    {
        std::shared_ptr<Transform2D> transform = get_transform();

        return Math::calc_view_mat(transform->get_position());
    }

    glm::mat4 Camera2D::get_projection_mat() const
    {
        return Math::calc_projection_mat(get_parent()->get_scene()->
            get_application()->get_game_framebuffer_size(), pixel_scale);
    }

    void Camera2D::load_impl()
    {
        set_pixel_scale(asset.get_pixel_scale());
    }
}
