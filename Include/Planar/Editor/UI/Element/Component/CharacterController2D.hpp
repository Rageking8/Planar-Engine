#pragma once

#include "Planar/Editor/UI/Element/Component/Core/Component.hpp"
#include "Planar/Engine/Component/CharacterController2D.hpp"
#include "Planar/Engine/UI/ImGui/Element/Drag/Drag.hpp"
#include "Planar/Engine/UI/ImGui/Element/Checkbox.hpp"

namespace Planar::Editor::UI::Element::Component
{
    class CharacterController2D :
        public Core::Component<Engine::Component::CharacterController2D>
    {
    public:
        CharacterController2D();

        virtual bool get_modified(bool reset = true) override;

    private:
        Engine::UI::ImGui::Element::Drag::DragFloat1 speed;
        Engine::UI::ImGui::Element::Checkbox enable_x_flip;
        Engine::UI::ImGui::Element::Checkbox inverse_x_flip;

        virtual void render_content() override;

        virtual void set_values_impl(ComponentType* character_controller)
            override;
        virtual void write_values_impl(ComponentType* character_controller)
            override;
    };
}
