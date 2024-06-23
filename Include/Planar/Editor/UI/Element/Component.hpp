#pragma once

#include "Planar/Engine/UI/ImGui/Element/Element.hpp"
#include "Planar/Engine/UI/ImGui/Element/Tree.hpp"
#include "Planar/Engine/UI/ImGui/Element/Checkbox.hpp"

#include <string>

namespace Planar::Editor::UI::Element
{
    class Component :
        public Engine::UI::ImGui::Element::Element
    {
    public:
        Component();

        virtual void render() override;

        void set_text(const std::string& new_text);
        void set_show_active_checkbox(bool new_show_active_checkbox);

    private:
        Engine::UI::ImGui::Element::Tree header;
        Engine::UI::ImGui::Element::Checkbox active_checkbox;
        bool show_active_checkbox;

        void render_active_checkbox();
    };
}
