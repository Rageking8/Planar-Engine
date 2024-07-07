#include "Planar/Editor/UI/Element/Component/Transform2D.hpp"
#include "Planar/Editor/UI/Element/Component/Core/ComponentMacros.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"

namespace Planar::Editor::UI::Element::Component
{
    Transform2D::Transform2D() :
        Component("Transform2D", false), position("Position",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FILL,
        0.f, 0.f, 20.f }, 100.f, true), rotation("Rotation",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FILL,
        0.f, 0.f, 20.f }, 100.f, true), scale("Scale",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FILL,
        0.f, 0.f, 20.f }, 100.f, true)
    {

    }

    bool Transform2D::get_modified(bool reset)
    {
        bool position_modified = position.get_modified(reset);
        bool rotation_modified = rotation.get_modified(reset);
        bool scale_modified = scale.get_modified(reset);

        return position_modified || rotation_modified ||
            scale_modified;
    }

    PLANAR_DEFINE_ELEMENT_COMPONENT_GET_SET_DRAG_2(Transform2D,
        Engine::Math::Pos2Df, position)
    PLANAR_DEFINE_ELEMENT_COMPONENT_GET_SET_DRAG_1(Transform2D,
        rotation)
    PLANAR_DEFINE_ELEMENT_COMPONENT_GET_SET_DRAG_2(Transform2D,
        Engine::Math::Size2Df, scale)

    void Transform2D::render_content()
    {
        position.render();
        Engine::UI::ImGui::Core::Cursor::move_y(10.f);
        rotation.render();
        Engine::UI::ImGui::Core::Cursor::move_y(10.f);
        scale.render();
    }

    void Transform2D::set_values_impl(ComponentType* transform)
    {
        set_position(transform->get_position());
        set_rotation(transform->get_rotation());
        set_scale(transform->get_scale());
    }

    void Transform2D::write_values_impl(ComponentType* transform)
    {
        transform->set_position(get_position());
        transform->set_rotation(get_rotation());
        transform->set_scale(get_scale());
    }
}
