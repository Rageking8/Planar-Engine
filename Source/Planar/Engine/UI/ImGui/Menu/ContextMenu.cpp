#include "Planar/Engine/UI/ImGui/Menu/ContextMenu.hpp"
#include "Planar/Engine/UI/ImGui/Window/WindowFlags.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/Math/Pos2D.hpp"

#include "ThirdParty/ImGui/imgui.h"

#include <memory>

namespace Planar::Engine::UI::ImGui::Menu
{
    ContextMenu::ContextMenu() : window("ContextMenu", {}, false),
        wait_frames{}
    {
        using namespace Planar::Engine::Core::Utils::EnumClass;

        window.set_flags(ImGui::Window::WindowFlags::MINIMAL |
            ImGui::Window::WindowFlags::ALWAYS_AUTO_RESIZE);
    }

    void ContextMenu::render(const std::function<bool()>& content)
    {
        bool right_clicked = is_item_hovered() &&
            ::ImGui::IsMouseReleased(ImGuiMouseButton_Right);

        if (right_clicked)
        {
            wait_frames = 2;

            Math::Pos2Df position{ ::ImGui::GetMousePos().x,
                ::ImGui::GetMousePos().y };
            window.set_position(position - 5.f);
            window.reset_first_render();
            window.set_active(true);
        }

        std::unique_ptr<Window::Window::Scope> result =
            window.render();

        if (!result)
        {
            return;
        }

        if (content && content())
        {
            window.set_active(false);

            return;
        }

        window.set_active(wait_frames != 0 ||
            ::ImGui::IsWindowHovered());
        wait_frames = wait_frames > 0 ? wait_frames - 1 : 0;
    }
}
