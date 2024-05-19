#include "Planar/Engine/UI/ImGui/Menu/WindowMenuBar.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Menu
{
    WindowMenuBar::WindowMenuBar()
    {

    }

    WindowMenuBar::~WindowMenuBar()
    {
        if (started)
        {
            ::ImGui::EndMenuBar();
        }
    }

    bool WindowMenuBar::start()
    {
        started = ::ImGui::BeginMenuBar();

        return started;
    }
}
