#pragma once

#include "Planar/Engine/UI/ImGui/Element/Element.hpp"
#include "Planar/Engine/UI/ImGui/Element/Tree.hpp"
#include "Planar/Engine/UI/ImGui/Element/Checkbox.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>
#include <memory>

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Component, Component)

namespace Planar::Editor::UI::Element
{
    class Component :
        public Engine::UI::ImGui::Element::Element
    {
    public:
        Component(const std::string& text);

        virtual void render() override;

        virtual bool get_modified(bool reset = true) = 0;

        virtual void set(
            std::shared_ptr<Engine::Component::Component> component) = 0;

        void set_text(const std::string& new_text);
        void set_show_active_checkbox(bool new_show_active_checkbox);

    private:
        Engine::UI::ImGui::Element::Tree header;
        Engine::UI::ImGui::Element::Checkbox active_checkbox;
        bool show_active_checkbox;
        float top_padding;

        virtual void render_content();
        void render_content_impl();

        void render_active_checkbox();
    };
}
