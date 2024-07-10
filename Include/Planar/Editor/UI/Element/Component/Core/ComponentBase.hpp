#pragma once

#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"
#include "Planar/Engine/UI/ImGui/Element/Element.hpp"
#include "Planar/Engine/UI/ImGui/Element/Tree.hpp"
#include "Planar/Engine/UI/ImGui/Element/Checkbox.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>
#include <memory>

PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Core, Editor)
PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Component::Core, ComponentBase)

namespace Planar::Editor::UI::Element::Component::Core
{
    class ComponentBase :
        public Engine::UI::ImGui::Element::Element
    {
    public:
        ComponentBase(const std::string& text,
            bool show_active_checkbox = true);

        virtual void render() override;

        virtual bool get_modified(bool reset = true) = 0;

        void set_values(
            std::shared_ptr<Engine::Component::Core::ComponentBase>
            component);
        bool write_values(
            std::shared_ptr<Engine::Component::Core::ComponentBase>
            component, bool force = false);

        void set_editor(Editor::Core::Editor* new_editor);

        void set_header_text(const std::string& new_header_text);
        void set_header_id(const std::string& new_header_id);
        void set_show_active_checkbox(bool new_show_active_checkbox);

    protected:
        Editor::Core::Editor* editor;
        Engine::UI::ImGui::Element::Checkbox active_checkbox;

    private:
        Engine::UI::ImGui::Element::Tree header;
        bool show_active_checkbox;
        float top_padding;
        float bottom_padding;

        virtual void render_content() = 0;
        void render_content_impl();

        void render_active_checkbox();

        virtual void set_values_impl(
            std::shared_ptr<Engine::Component::Core::ComponentBase>&
            component) = 0;
        virtual void write_values_impl(
            std::shared_ptr<Engine::Component::Core::ComponentBase>&
            component) = 0;
    };
}
