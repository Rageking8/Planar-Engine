#include "Planar/Engine/Component/Transform2D.hpp"

#include "ThirdParty/glm/mat4x4.hpp"
#include "ThirdParty/glm/gtc/matrix_transform.hpp"

namespace Planar::Engine::Component
{
    Transform2D::Transform2D(GameObject::GameObject* parent,
        bool generate_guid) : Component(parent, generate_guid),
        rotation{}, scale{ 1.f }
    {

    }

    PLANAR_DEFINE_COMPONENT_GET_SET(Transform2D, Math::Pos2Df, position)

    void Transform2D::translate(Math::Size2Df delta)
    {
        position.x += delta.width;
        position.y += delta.height;
        asset.set_position(position);
    }

    void Transform2D::translate_x(float delta)
    {
        translate({ delta, 0.f });
    }

    void Transform2D::translate_y(float delta)
    {
        translate({ 0.f, delta });
    }

    PLANAR_DEFINE_COMPONENT_GET_SET(Transform2D, float, rotation)
    PLANAR_DEFINE_COMPONENT_GET_SET(Transform2D, Math::Size2Df, scale)

    glm::mat4 Transform2D::get_model_mat() const
    {
        glm::mat4 model(1.f);
        model = glm::translate(model, { position.x, position.y, 0.f });
        model = glm::rotate(model, glm::radians(rotation),
            { 0.f, 0.f, 1.f });
        model = glm::scale(model, { scale.width, scale.height, 1.f });

        return model;
    }

    void Transform2D::load_impl()
    {
        set_position(asset.get_position());
        set_rotation(asset.get_rotation());
        set_scale(asset.get_scale());
    }
}
