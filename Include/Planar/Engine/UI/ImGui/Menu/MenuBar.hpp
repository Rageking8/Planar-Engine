#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

#include <string>
#include <functional>

namespace Planar::Engine::UI::ImGui::Menu
{
    class PLANAR_API MenuBar
    {
    public:
        MenuBar();
        virtual ~MenuBar();

        virtual bool start() = 0;

        void add_menu(const std::string& name,
            std::function<void()> content) const;

    protected:
        bool started;
    };
}
