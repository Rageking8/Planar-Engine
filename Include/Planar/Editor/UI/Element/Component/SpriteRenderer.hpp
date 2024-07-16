#pragma once

#include "Planar/Editor/UI/Element/Component/Core/Component.hpp"
#include "Planar/Engine/Component/SpriteRenderer.hpp"
#include "Planar/Engine/UI/ImGui/Element/Checkbox.hpp"
#include "Planar/Engine/UI/ImGui/Element/InputField.hpp"
#include "Planar/Engine/UI/ImGui/Element/Button/Button.hpp"

#include <string>

namespace Planar::Editor::UI::Element::Component
{
    class SpriteRenderer :
        public Core::Component<Engine::Component::SpriteRenderer>
    {
    public:
        SpriteRenderer();

        virtual bool get_modified(bool reset = true) override;

    private:
        bool sprite_modified;
        std::string sprite;
        Engine::UI::ImGui::Element::InputField sprite_input;
        Engine::UI::ImGui::Element::Button::Button sprite_select_button;
        Engine::UI::ImGui::Element::Checkbox flip_x_checkbox;
        Engine::UI::ImGui::Element::Checkbox flip_y_checkbox;

        virtual void render_content() override;

        virtual void set_values_impl(ComponentType* sprite_renderer)
            override;
        virtual void write_values_impl(ComponentType* sprite_renderer)
            override;

        void update_sprite(const std::string& new_sprite);
    };
}
