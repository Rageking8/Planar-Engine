#include "Planar/Engine/UI/ImGui/ImGuiWindow.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui
{
    ImGuiWindow::ImGuiWindow(const std::string& name)
    {
        ::ImGui::Begin(name.c_str());
    }

    ImGuiWindow::~ImGuiWindow()
    {
        ::ImGui::End();
    }
}
