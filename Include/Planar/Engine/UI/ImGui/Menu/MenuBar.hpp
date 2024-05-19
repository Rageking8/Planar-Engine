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
        bool add_menu_item(const std::string& label,
            const std::string& shortcut = "",
            bool selected = false, bool enabled = true) const;
        void add_menu_separator() const;

    protected:
        bool started;
    };
}
