#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Math/Pos2D.hpp"
#include "Planar/Engine/UI/ImGui/Window/Window.hpp"

#include <optional>
#include <functional>

namespace Planar::Engine::UI::ImGui::Menu
{
    class PLANAR_API ContextMenu
    {
    public:
        ContextMenu();

        bool render(
            const std::function<bool()>& content_override = {},
            std::optional<bool> right_clicked_override = {});

        void set_content(const std::function<bool()>& new_content);
        void clear_content();

    private:
        Window::Window window;
        std::function<bool()> content;
        Math::Pos2Df temp_mouse_position;
        float offset;
        unsigned wait_frames;
    };
}
