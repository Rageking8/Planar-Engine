#include "Planar/Editor/UI/Element/Transform2D.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"
#include "Planar/Engine/Core/Utils/Checks/Assert.hpp"
#include "Planar/Engine/Core/Utils/Cast/Cast.hpp"
#include "Planar/Engine/Component/Transform2D.hpp"
#include "Planar/Engine/Component/Component.hpp"
#include "Planar/Engine/Component/ComponentType.hpp"

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

    bool Transform2D::get_modified(bool reset)
    {
        bool position_modified = position.get_modified(reset);
        bool rotation_modified = rotation.get_modified(reset);

        return position_modified || rotation_modified;
    }

    void Transform2D::set(
        std::shared_ptr<Engine::Component::Component> component)
    {
        Engine::Component::Transform2D* transform =
            get_engine_component(component);

        set_position(transform->get_position());
        set_rotation(transform->get_rotation());

        position.get_modified();
        rotation.get_modified();
    }

    bool Transform2D::write(
        std::shared_ptr<Engine::Component::Component> component,
        bool force)
    {
        if (!(force || get_modified()))
        {
            return false;
        }

        Engine::Component::Transform2D* transform =
            get_engine_component(component);

        transform->set_position(get_position());
        transform->set_rotation(get_rotation());

        return true;
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

    Engine::Component::Transform2D* Transform2D::get_engine_component(
        std::shared_ptr<Engine::Component::Component>& component)
    {
        PLANAR_ASSERT(component->get_type() ==
            Engine::Component::ComponentType::Transform2D,
            "`component` has wrong type");

        return Engine::Core::Utils::Cast::shared_ptr_downcast
            <Engine::Component::Transform2D>(component);
    }
}
