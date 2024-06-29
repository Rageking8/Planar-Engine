#pragma once

#include "Planar/Editor/UI/Element/Component.hpp"
#include "Planar/Engine/UI/ImGui/Element/Drag/DragFloat.hpp"
#include "Planar/Engine/Math/Pos2D.hpp"

namespace Planar::Editor::UI::Element
{
    class Transform2D : public Component
    {
    public:
        Transform2D();

        Engine::Math::Pos2Df get_position() const;
        void set_position(Engine::Math::Pos2Df new_position);

        float get_rotation() const;
        void set_rotation(float new_rotation);

    private:
        Engine::UI::ImGui::Element::Drag::DragFloat2 position;
        Engine::UI::ImGui::Element::Drag::DragFloat1 rotation;

        virtual void render_content() override;
    };
}
