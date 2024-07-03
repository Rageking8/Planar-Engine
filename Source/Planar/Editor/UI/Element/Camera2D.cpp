#include "Planar/Editor/UI/Element/Camera2D.hpp"

namespace Planar::Editor::UI::Element
{
    Camera2D::Camera2D() : Component("Camera2D")
    {

    }

    bool Camera2D::get_modified(bool reset)
    {
        bool active_modified = active_checkbox.get_modified(reset);

        return active_modified;
    }

    void Camera2D::render_content()
    {

    }

    void Camera2D::set_values_impl(ComponentType* camera)
    {
        active_checkbox.set_value(camera->get_active());

        active_checkbox.get_modified();
    }

    void Camera2D::write_values_impl(ComponentType* camera)
    {
        camera->set_active(active_checkbox.get_value());
    }
}
