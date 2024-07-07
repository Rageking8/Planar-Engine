#include "Planar/Editor/UI/Element/Component/CameraController2D.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"

namespace Planar::Editor::UI::Element::Component
{
    CameraController2D::CameraController2D() :
        Component("CameraController2D"),
        horizontal_speed("Horizontal Speed",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FILL,
        0.f, 0.f, 20.f }, 150.f, true),
        vertical_speed("Vertical Speed",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FILL,
        0.f, 0.f, 20.f }, 150.f, true)
    {

    }

    bool CameraController2D::get_modified(bool reset)
    {
        bool active_modified = active_checkbox.get_modified(reset);
        bool horizontal_speed_modified = horizontal_speed.
            get_modified(reset);
        bool vertical_speed_modified = vertical_speed.
            get_modified(reset);

        return active_modified || horizontal_speed_modified ||
            vertical_speed_modified;
    }

    Engine::Math::Size2Df CameraController2D::get_horizontal_speed()
        const
    {
        return horizontal_speed.get_value();
    }

    void CameraController2D::set_horizontal_speed(
        Engine::Math::Size2Df new_horizontal_speed)
    {
        horizontal_speed.set_value(new_horizontal_speed.get_array());
    }

    Engine::Math::Size2Df CameraController2D::get_vertical_speed()
        const
    {
        return vertical_speed.get_value();
    }

    void CameraController2D::set_vertical_speed(
        Engine::Math::Size2Df new_vertical_speed)
    {
        vertical_speed.set_value(new_vertical_speed.get_array());
    }

    void CameraController2D::render_content()
    {
        horizontal_speed.render();
        Engine::UI::ImGui::Core::Cursor::move_y(10.f);
        vertical_speed.render();
    }

    void CameraController2D::set_values_impl(
        ComponentType* camera_controller)
    {
        active_checkbox.set_value(camera_controller->get_active());
        set_horizontal_speed(camera_controller->get_horizontal_speed());
        set_vertical_speed(camera_controller->get_vertical_speed());
    }

    void CameraController2D::write_values_impl(
        ComponentType* camera_controller)
    {
        camera_controller->set_active(active_checkbox.get_value());
        camera_controller->set_horizontal_speed(get_horizontal_speed());
        camera_controller->set_vertical_speed(get_vertical_speed());
    }
}
