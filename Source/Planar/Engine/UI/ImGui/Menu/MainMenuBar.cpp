#include "Planar/Engine/UI/ImGui/Menu/MainMenuBar.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Menu
{
    MainMenuBar::MainMenuBar()
    {

    }

    MainMenuBar::~MainMenuBar()
    {
        if (started)
        {
            ::ImGui::EndMainMenuBar();
        }
    }

    bool MainMenuBar::start()
    {
        started = ::ImGui::BeginMainMenuBar();

        return started;
    }
}
