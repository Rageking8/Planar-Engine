#include "Planar/Engine/UI/ImGui/ImGuiWindow.hpp"

#include "ThirdParty/ImGui/imgui.h"

namespace Planar::Engine::UI::ImGui
{
    ImGuiWindow::ImGuiWindow(const std::string& name,
        ImGuiWindowFlags flags)
    {
        if (Planar::Engine::Core::Utils::has(
            flags, ImGuiWindowFlags::FIT_TO_WINDOW))
        {
            ImGuiViewport* viewport = ::ImGui::GetMainViewport();
            ::ImGui::SetNextWindowPos(viewport->Pos);
            ::ImGui::SetNextWindowSize(viewport->Size);
        }

        ::ImGuiWindowFlags begin_flags{};

        if (Planar::Engine::Core::Utils::has(
            flags, ImGuiWindowFlags::MINIMAL))
        {
            begin_flags |= ImGuiWindowFlags_NoDecoration |
                ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground;
        }

        ::ImGui::Begin(name.c_str(), nullptr, begin_flags);
    }

    ImGuiWindow::~ImGuiWindow()
    {
        ::ImGui::End();
    }
}
