#include "Planar/Editor/UI/Element/ComponentBase.hpp"
#include "Planar/Engine/Component/Component.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Style/StyleVar.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/CursorScope.hpp"
#include "Planar/Engine/Core/Utils/Macros/FunctionalMacros.hpp"

#include <functional>

namespace Planar::Editor::UI::Element
{
    ComponentBase::ComponentBase(const std::string& text,
        bool show_active_checkbox) : header({ 10.f, 7.5f }, 24.f, 0.f,
        40.f, 10.f, true, true), active_checkbox(Engine::UI::ImGui::
        generate_unique_label(), true),
        show_active_checkbox{ show_active_checkbox },
        top_padding{ 10.f }, bottom_padding{ 10.f }
    {
        set_header_text(text);
    }

    void ComponentBase::render()
    {
        header.render({}, {}, PLANAR_CAPTURE_THIS(render_content_impl),
            show_active_checkbox ? PLANAR_CAPTURE_THIS(
            render_active_checkbox) : std::function<void()>{});
    }

    void ComponentBase::set_values(
        std::shared_ptr<Engine::Component::Component> component)
    {
        set_header_id(component->get_guid());
        set_values_impl(component);
    }

    bool ComponentBase::write_values(
        std::shared_ptr<Engine::Component::Component> component,
        bool force)
    {
        if (!(force || get_modified()))
        {
            return false;
        }

        write_values_impl(component);

        return true;
    }

    void ComponentBase::set_header_text(const std::string& new_header_text)
    {
        header.set_text(new_header_text);
    }

    void ComponentBase::set_header_id(const std::string& new_header_id)
    {
        header.set_id(new_header_id);
    }

    void ComponentBase::set_show_active_checkbox(
        bool new_show_active_checkbox)
    {
        show_active_checkbox = new_show_active_checkbox;
    }

    void ComponentBase::render_content_impl()
    {
        Engine::UI::ImGui::Core::Cursor::move_y(top_padding);

        render_content();

        Engine::UI::ImGui::Core::Cursor::move_y(bottom_padding);
    }

    void ComponentBase::render_active_checkbox()
    {
        using namespace Engine::UI;

        ImGui::Style::StyleVar style_var;
        style_var.set_frame_padding({ 0.f, 2.f });

        ImGui::Core::Cursor::CursorScope cursor_scope(
            ImGui::Core::Cursor::CursorScope::Mode::RELATIVE,
            0.f, 5.f);

        active_checkbox.render();
    }
}
