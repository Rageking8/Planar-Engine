#include "Planar/Engine/UI/ImGui/Menu/MenuBar.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Menu
{
    MenuBar::MenuBar() : started{}
    {

    }

    MenuBar::~MenuBar()
    {

    }

    void MenuBar::add_menu(const std::string& name,
        std::function<void()> content) const
    {
        if (::ImGui::BeginMenu(name.c_str()))
        {
            content();

            ::ImGui::EndMenu();
        }
    }
}
