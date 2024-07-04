#include "Planar/Editor/UI/Element/CameraController2D.hpp"

namespace Planar::Editor::UI::Element
{
    CameraController2D::CameraController2D() :
        Component("CameraController2D")
    {

    }

    bool CameraController2D::get_modified(bool reset)
    {
        bool active_modified = active_checkbox.get_modified(reset);

        return active_modified;
    }

    void CameraController2D::render_content()
    {

    }

    void CameraController2D::set_values_impl(ComponentType* camera)
    {
        active_checkbox.set_value(camera->get_active());

        active_checkbox.get_modified();
    }

    void CameraController2D::write_values_impl(ComponentType* camera)
    {
        camera->set_active(active_checkbox.get_value());
    }
}
