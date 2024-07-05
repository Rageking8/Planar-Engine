#include "Planar/Editor/UI/Element/Component/Transform2D.hpp"
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

    Engine::Math::Pos2Df Transform2D::get_position() const
    {
        return position.get_value();
    }

    void Transform2D::set_position(Engine::Math::Pos2Df new_position)
    {
        position.set_value(new_position.get_array());
    }

    float Transform2D::get_rotation() const
    {
        return rotation.get_x();
    }

    void Transform2D::set_rotation(float new_rotation)
    {
        rotation.set_x(new_rotation);
    }

    Engine::Math::Size2Df Transform2D::get_scale() const
    {
        return scale.get_value();
    }

    void Transform2D::set_scale(Engine::Math::Size2Df new_scale)
    {
        scale.set_value(new_scale.get_array());
    }

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

        position.get_modified();
        rotation.get_modified();
        scale.get_modified();
    }

    void Transform2D::write_values_impl(ComponentType* transform)
    {
        transform->set_position(get_position());
        transform->set_rotation(get_rotation());
        transform->set_scale(get_scale());
    }
}