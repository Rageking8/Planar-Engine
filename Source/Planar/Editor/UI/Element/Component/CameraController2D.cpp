#include "Planar/Editor/UI/Element/Component/CameraController2D.hpp"
#include "Planar/Editor/UI/Element/Component/Core/ComponentMacros.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"

namespace Planar::Editor::UI::Element::Component
{
    CameraController2D::CameraController2D() :
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
            horizontal_speed, vertical_speed);
    }

    PLANAR_DEFINE_ELEMENT_COMPONENT_GET_SET_DRAG_2(CameraController2D,
        Engine::Math::Size2Df, horizontal_speed)
    PLANAR_DEFINE_ELEMENT_COMPONENT_GET_SET_DRAG_2(CameraController2D,
        Engine::Math::Size2Df, vertical_speed)

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
