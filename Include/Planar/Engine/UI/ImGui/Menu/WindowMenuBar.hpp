#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/UI/ImGui/Menu/MenuBar.hpp"

namespace Planar::Engine::UI::ImGui::Menu
{
    class PLANAR_API WindowMenuBar : public MenuBar
    {
    public:
        WindowMenuBar();
        ~WindowMenuBar();

        virtual bool start() override;
    };
}
