#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/UI/ImGui/Window/Window.hpp"

#include <functional>

namespace Planar::Engine::UI::ImGui::Menu
{
    class PLANAR_API ContextMenu
    {
    public:
        ContextMenu();

        bool render(
            const std::function<bool()>& content_override = {});

        void set_content(const std::function<bool()>& new_content);

        void add_separator();

    private:
        Window::Window window;
        std::function<bool()> content;
        unsigned wait_frames;
    };
}
