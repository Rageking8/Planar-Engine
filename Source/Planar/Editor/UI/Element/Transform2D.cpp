#include "Planar/Editor/UI/Element/Transform2D.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"

namespace Planar::Editor::UI::Element
{
    Transform2D::Transform2D() :
        Component("Transform2D"), position("Position", "",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FILL,
        0.f, 0.f, 20.f }, 100.f), rotation("Rotation", "",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FILL,
        0.f, 0.f, 20.f }, 100.f)
    {

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

    void Transform2D::render_content()
    {
        position.render();
        Engine::UI::ImGui::Core::Cursor::move_y(10.f);
        rotation.render();
    }
}
