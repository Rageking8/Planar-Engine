#include "Planar/Engine/UI/ImGui/Menu/ContextMenu.hpp"
#include "Planar/Engine/UI/ImGui/Window/WindowFlags.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/Math/Pos2D.hpp"

#include "ThirdParty/ImGui/imgui.h"

#include <memory>

namespace Planar::Engine::UI::ImGui::Menu
{
    ContextMenu::ContextMenu() : window("ContextMenu", {}, false),
        offset{ 5.f }, wait_frames{}
    {
        using namespace Planar::Engine::Core::Utils::EnumClass;

        window.set_padding({ { 20.f, 14.f } });
        window.set_flags(ImGui::Window::WindowFlags::MINIMAL |
            ImGui::Window::WindowFlags::ALWAYS_AUTO_RESIZE);
    }

    bool ContextMenu::render(
        const std::function<bool()>& content_override,
        std::optional<bool> right_clicked_override)
    {
        bool right_clicked = right_clicked_override ?
            *right_clicked_override : (is_item_hovered() &&
            ::ImGui::IsMouseReleased(ImGuiMouseButton_Right));

        if (right_clicked)
        {
            wait_frames = 2;

            Math::Pos2Df position{ ::ImGui::GetMousePos().x,
                ::ImGui::GetMousePos().y };
            window.set_position(position - offset);
            window.reset_first_render();
            window.set_active(true);
        }

        std::unique_ptr<Window::Window::Scope> result =
            window.render();

        if (!result)
        {
            return false;
        }

        if ((content && content()) ||
            (content_override && content_override()))
        {
            window.set_active(false);
            clear_content();

            return false;
        }

        window.set_active(wait_frames != 0 ||
            ::ImGui::IsWindowHovered());
        wait_frames = wait_frames > 0 ? wait_frames - 1 : 0;

        return window.get_active();
    }

    void ContextMenu::set_content(
        const std::function<bool()>& new_content)
    {
        content = new_content;
    }

    void ContextMenu::clear_content()
    {
        content = {};
    }

    void ContextMenu::add_separator()
    {
        separator(2.5f);
    }
}
