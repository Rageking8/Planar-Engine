#include "Planar/Engine/UI/ImGui/ImGuiMainMenuBar.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui
{
    ImGuiMainMenuBar::ImGuiMainMenuBar() : started{}
    {

    }

    ImGuiMainMenuBar::~ImGuiMainMenuBar()
    {
        if (started)
        {
            ::ImGui::EndMainMenuBar();
        }
    }

    bool ImGuiMainMenuBar::start()
    {
        started = ::ImGui::BeginMainMenuBar();

        return started;
    }

    void ImGuiMainMenuBar::add_menu(const std::string& name,
        std::function<void()> content) const
    {
        if (::ImGui::BeginMenu(name.c_str()))
        {
            content();

            ::ImGui::EndMenu();
        }
    }

    bool ImGuiMainMenuBar::add_menu_item(const std::string& label,
        const std::string& shortcut, bool selected, bool enabled) const
    {
        return ::ImGui::MenuItem(label.c_str(), shortcut.c_str(),
            selected, enabled);
    }

    void ImGuiMainMenuBar::add_menu_separator() const
    {
        ::ImGui::Separator();
    }
}
