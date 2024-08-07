#include "Planar/Editor/UI/Element/Component/CameraController2D.hpp"
#include "Planar/Editor/Core/Editor.hpp"
#include "Planar/Engine/Component/Transform2D.hpp"
#include "Planar/Engine/UI/ImGui/Core/Size/Width.hpp"
#include "Planar/Engine/Core/Utils/Macros/FunctionalMacros.hpp"

namespace Planar::Editor::UI::Element::Component
{
    CameraController2D::CameraController2D() :
        mode_drop_down("Mode",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FILL,
        0.f, 0.f, 20.f }, 160.f, true, { "Free", "Track" }),
        horizontal_speed("Horizontal Speed",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FILL,
        0.f, 0.f, 20.f }, 160.f, true),
        vertical_speed("Vertical Speed",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FILL,
        0.f, 0.f, 20.f }, 160.f, true),
        tracked_transform("Transform", "GameObject",
        PLANAR_CAPTURE_THIS_PARAM1(update_tracked_transform_text),
        PLANAR_CAPTURE_THIS_PARAM1_RET(map_tracked_transform),
        20.f, 160.f),
        horizontal_lerp("Horizontal Lerp",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FILL,
        0.f, 0.f, 20.f }, 160.f, true),
        vertical_lerp("Vertical Lerp",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FILL,
        0.f, 0.f, 20.f }, 160.f, true)
    {

    }

    bool CameraController2D::get_modified(bool reset)
    {
        return modified_helper(reset, active_checkbox,
            mode_drop_down, horizontal_speed, vertical_speed,
            tracked_transform, horizontal_lerp, vertical_lerp);
    }

    void CameraController2D::render_content()
    {
        render_helper(mode_drop_down);

        if (mode_drop_down.get_selected_text() == "Free")
        {
            render_helper(horizontal_speed, vertical_speed);
        }
        else if (mode_drop_down.get_selected_text() == "Track")
        {
            render_helper(tracked_transform, horizontal_lerp,
                vertical_lerp);
        }
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
        tracked_transform.set_asset(camera_controller->
            get_tracked_transform(), false, true);
        horizontal_lerp.set_x(camera_controller->get_horizontal_lerp());
        vertical_lerp.set_x(camera_controller->get_vertical_lerp());
    }

    void CameraController2D::write_values_impl(
        ComponentType* camera_controller)
    {
        camera_controller->set_active(active_checkbox.get_value());
        camera_controller->set_mode(mode_drop_down.get_selected_text());
        camera_controller->set_horizontal_speed(horizontal_speed.
            get_value());
        camera_controller->set_vertical_speed(vertical_speed.get_value());
        camera_controller->set_tracked_transform(tracked_transform.
            get_asset());
        camera_controller->set_horizontal_lerp(horizontal_lerp.get_x());
        camera_controller->set_vertical_lerp(vertical_lerp.get_x());
    }

    std::string CameraController2D::map_tracked_transform(
        std::string asset)
    {
        return editor->get_current_scene()->get_root()->
            find_game_object(asset)->get_transform()->get_guid();
    }

    void CameraController2D::update_tracked_transform_text(
        std::string new_tracked_transform)
    {
        tracked_transform.set_text(editor->get_current_scene()->
            get_component_reference(new_tracked_transform)->
            get_parent()->get_name());
    }
}
