#include "Planar/Editor/UI/Element/Component/Camera2D.hpp"

namespace Planar::Editor::UI::Element::Component
{
    Camera2D::Camera2D() : pixel_scale("Pixel Scale",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FILL,
        0.f, 0.f, 20.f }, 125.f, true)
    {

    }

    bool Camera2D::get_modified(bool reset)
    {
        return modified_helper(reset, active_checkbox, pixel_scale);
    }

    void Camera2D::render_content()
    {
        render_helper(pixel_scale);
    }

    void Camera2D::set_values_impl(ComponentType* camera)
    {
        active_checkbox.set_value(camera->get_active());
        pixel_scale.set_x(camera->get_pixel_scale());
    }

    void Camera2D::write_values_impl(ComponentType* camera)
    {
        camera->set_active(active_checkbox.get_value());
        camera->set_pixel_scale(pixel_scale.get_x());
    }
}
