#include "Planar/Editor/UI/Element/Component.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Style/StyleVar.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/CursorScope.hpp"
#include "Planar/Engine/Core/Utils/Macros/FunctionalMacros.hpp"

#include <functional>

namespace Planar::Editor::UI::Element
{
    Component::Component(const std::string& text) :
        header({ 10.f, 7.5f }, 24.f, 0.f, 40.f, 10.f, true, true),
        active_checkbox(Engine::UI::ImGui::generate_unique_label(),
        true), show_active_checkbox{ true }, top_padding{ 10.f }
    {
        set_text(text);
    }

    void Component::render()
    {
        header.render({}, {}, PLANAR_CAPTURE_THIS(render_content_impl),
            show_active_checkbox ? PLANAR_CAPTURE_THIS(
            render_active_checkbox) : std::function<void()>{});
    }

    void Component::set_text(const std::string& new_text)
    {
        header.set_text(new_text);
    }

    void Component::set_show_active_checkbox(
        bool new_show_active_checkbox)
    {
        show_active_checkbox = new_show_active_checkbox;
    }

    void Component::render_content()
    {

    }

    void Component::render_content_impl()
    {
        Engine::UI::ImGui::Core::Cursor::move_y(top_padding);

        render_content();
    }

    void Component::render_active_checkbox()
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
