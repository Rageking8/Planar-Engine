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

        void render(const std::function<bool()>& content = {});

    private:
        Window::Window window;
        unsigned wait_frames;
    };
}
