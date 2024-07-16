#include "Planar/Editor/UI/Element/Component/CameraController2D.hpp"
#include "Planar/Engine/UI/ImGui/Core/Size/Width.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"

namespace Planar::Editor::UI::Element::Component
{
    CameraController2D::CameraController2D() :
        mode_drop_down("Mode",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FILL,
        0.f, 0.f, 20.f }, 160.f, false, { "Free" }),
        horizontal_speed("Horizontal Speed",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FILL,
        0.f, 0.f, 20.f }, 160.f, true),
        vertical_speed("Vertical Speed",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FILL,
        0.f, 0.f, 20.f }, 160.f, true)
    {

    }

    bool CameraController2D::get_modified(bool reset)
    {
        return modified_helper(reset, active_checkbox,
            mode_drop_down, horizontal_speed, vertical_speed);
    }

    void CameraController2D::render_content()
    {
        mode_drop_down.render();
        Engine::UI::ImGui::Core::Cursor::move_y(-4.f);
        horizontal_speed.render();
        Engine::UI::ImGui::Core::Cursor::move_y(10.f);
        vertical_speed.render();
    }

    void CameraController2D::set_values_impl(
        ComponentType* camera_controller)
    {
        active_checkbox.set_value(camera_controller->get_active());
        mode_drop_down.set_selected_text(camera_controller->
            get_mode(), true);
        horizontal_speed.set_value(camera_controller->
            get_horizontal_speed().get_array());
        vertical_speed.set_value(camera_controller->
            get_vertical_speed().get_array());
    }

    void CameraController2D::write_values_impl(
        ComponentType* camera_controller)
    {
        camera_controller->set_active(active_checkbox.get_value());
        camera_controller->set_mode(mode_drop_down.get_selected_text());
        camera_controller->set_horizontal_speed(horizontal_speed.
            get_value());
        camera_controller->set_vertical_speed(vertical_speed.get_value());
    }
}
