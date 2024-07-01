#include "Planar/Editor/UI/Element/Camera2D.hpp"
#include "Planar/Engine/Core/Utils/Cast/Cast.hpp"
#include "Planar/Engine/Core/Utils/Checks/Assert.hpp"
#include "Planar/Engine/Component/Camera2D.hpp"
#include "Planar/Engine/Component/Component.hpp"

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
        Engine::Component::Camera2D* camera =
            get_engine_component(component);
    }

    bool Camera2D::write(
        std::shared_ptr<Engine::Component::Component> component, bool force)
    {
        if (!(force || get_modified()))
        {
            return false;
        }

        Engine::Component::Camera2D* camera =
            get_engine_component(component);

        return true;
    }

    void Camera2D::render_content()
    {

    }

    Engine::Component::Camera2D* Camera2D::get_engine_component(
        std::shared_ptr<Engine::Component::Component>& component)
    {
        PLANAR_ASSERT(component->get_type() ==
            Engine::Component::ComponentType::Camera2D,
            "`component` has wrong type");

        return Engine::Core::Utils::Cast::shared_ptr_downcast
            <Engine::Component::Camera2D>(component);
    }
}
