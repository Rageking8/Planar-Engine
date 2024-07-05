#pragma once

#include "Planar/Editor/UI/Element/Component/Component.hpp"
#include "Planar/Engine/Math/Pos2D.hpp"
#include "Planar/Engine/Math/Size2D.hpp"
#include "Planar/Engine/Component/Transform2D.hpp"
#include "Planar/Engine/UI/ImGui/Element/Drag/DragFloat.hpp"

namespace Planar::Editor::UI::Element::Component
{
    class Transform2D : public Component<Engine::Component::Transform2D>
    {
    public:
        Transform2D();

        virtual bool get_modified(bool reset = true) override;

        Engine::Math::Pos2Df get_position() const;
        void set_position(Engine::Math::Pos2Df new_position);

        float get_rotation() const;
        void set_rotation(float new_rotation);

        Engine::Math::Size2Df get_scale() const;
        void set_scale(Engine::Math::Size2Df new_scale);

    private:
        Engine::UI::ImGui::Element::Drag::DragFloat2 position;
        Engine::UI::ImGui::Element::Drag::DragFloat1 rotation;
        Engine::UI::ImGui::Element::Drag::DragFloat2 scale;

        virtual void render_content() override;

        virtual void set_values_impl(ComponentType* transform) override;
        virtual void write_values_impl(ComponentType* transform) override;
    };
}
