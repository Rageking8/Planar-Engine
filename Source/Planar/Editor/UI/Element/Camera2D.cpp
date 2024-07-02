#include "Planar/Editor/UI/Element/Camera2D.hpp"
#include "Planar/Engine/Component/Camera2D.hpp"
#include "Planar/Engine/Component/Component.hpp"
#include "Planar/Engine/Component/ComponentFunction.hpp"

namespace Planar::Editor::UI::Element
{
    Camera2D::Camera2D() : Component("Camera2D")
    {

    }

    bool Camera2D::get_modified(bool reset)
    {
        return false;
    }

    void Camera2D::set(
        std::shared_ptr<Engine::Component::Component> component)
    {
        auto* camera = Engine::Component::component_downcast
            <Engine::Component::Camera2D>(component);
    }

    bool Camera2D::write(
        std::shared_ptr<Engine::Component::Component> component, bool force)
    {
        if (!(force || get_modified()))
        {
            return false;
        }

        auto* camera = Engine::Component::component_downcast
            <Engine::Component::Camera2D>(component);

        return true;
    }

    void Camera2D::render_content()
    {

    }
}
