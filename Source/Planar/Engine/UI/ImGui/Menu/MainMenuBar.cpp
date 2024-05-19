#include "Planar/Engine/UI/ImGui/Menu/MainMenuBar.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui::Menu
{
    MainMenuBar::MainMenuBar() : started{}
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

    void MainMenuBar::add_menu(const std::string& name,
        std::function<void()> content) const
    {
        if (::ImGui::BeginMenu(name.c_str()))
        {
            content();

            ::ImGui::EndMenu();
        }
    }

    bool MainMenuBar::add_menu_item(const std::string& label,
        const std::string& shortcut, bool selected, bool enabled) const
    {
        return ::ImGui::MenuItem(label.c_str(), shortcut.c_str(),
            selected, enabled);
    }

    void MainMenuBar::add_menu_separator() const
    {
        ::ImGui::Separator();
    }
}
