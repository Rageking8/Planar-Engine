#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/UI/ImGui/Menu/MenuBar.hpp"

namespace Planar::Engine::UI::ImGui::Menu
{
    class PLANAR_API MainMenuBar : public MenuBar
    {
    public:
        MainMenuBar();
        ~MainMenuBar();

        virtual bool start() override;
    };
}
