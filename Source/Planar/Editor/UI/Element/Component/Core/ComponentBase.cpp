#include "Planar/Editor/UI/Element/Component/Core/ComponentBase.hpp"
#include "Planar/Engine/Component/Core/ComponentBase.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Style/StyleVar.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/MoveMode.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/CursorScope.hpp"
#include "Planar/Engine/Core/Utils/Macros/FunctionalMacros.hpp"

namespace Planar::Editor::UI::Element::Component::Core
{
    ComponentBase::ComponentBase(const std::string& text,
        bool show_active_checkbox) : active_checkbox(
        Engine::UI::ImGui::generate_unique_label(), true),
        header({ 10.f, 7.5f }, 24.f, 0.f, 40.f, 10.f, true, true),
        show_active_checkbox{ show_active_checkbox },
        vertical_padding{ 10.f }
    {
        set_header_text(text);
    }

    void ComponentBase::render()
    {
        render({});
    }

    void ComponentBase::render(
        const std::function<void(std::string)>& right_click_callback)
    {
        header.render({}, right_click_callback ?
            PLANAR_CAPTURE_REF_ARG1(right_click_callback, header.get_id())
            : std::function<void()>{}, PLANAR_CAPTURE_THIS(
            render_content_impl), show_active_checkbox ?
            PLANAR_CAPTURE_THIS(render_active_checkbox) :
            std::function<void()>{});
    }

    void ComponentBase::set_values(
        std::shared_ptr<Engine::Component::Core::ComponentBase>
        component)
    {
        set_header_id(component->get_guid());
        set_values_impl(component);
    }

    bool ComponentBase::write_values(
        std::shared_ptr<Engine::Component::Core::ComponentBase>
        component, bool force)
    {
        if (!(force || get_modified()))
        {
            return false;
        }

        write_values_impl(component);

        return true;
    }

    void ComponentBase::set_editor(Editor::Core::Editor* new_editor)
    {
        editor = new_editor;
    }

    void ComponentBase::set_header_text(
        const std::string& new_header_text)
    {
        header.set_text(new_header_text);
    }

    void ComponentBase::set_header_id(
        const std::string& new_header_id)
    {
        header.set_id(new_header_id);
    }

    void ComponentBase::set_show_active_checkbox(
        bool new_show_active_checkbox)
    {
        show_active_checkbox = new_show_active_checkbox;
    }

    void ComponentBase::render_with_padding(
        Engine::UI::ImGui::Element::Element& element)
    {
        Engine::UI::ImGui::Core::Cursor::move_y(
            Engine::UI::ImGui::Core::Cursor::MoveMode::DUMMY,
            vertical_padding, false);
        element.render();
    }

    void ComponentBase::render_content_impl()
    {
        render_content();
        Engine::UI::ImGui::Core::Cursor::move_y(
            Engine::UI::ImGui::Core::Cursor::MoveMode::DUMMY,
            vertical_padding, false);
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
