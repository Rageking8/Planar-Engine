#include "Planar/Editor/Scene/SelectProjectScene.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/ImGuiWindow.hpp"
#include "Planar/Engine/UI/ImGui/ImGuiWindowFlags.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"

#include <iostream>

namespace Planar::Editor::Scene
{
    void SelectProjectScene::render()
    {
        using namespace Planar::Engine::Core::Utils;

        Planar::Engine::UI::ImGui::ImGuiWindow window(
            "Select Project",
            Planar::Engine::UI::ImGui::ImGuiWindowFlags::FIT_TO_WINDOW |
            Planar::Engine::UI::ImGui::ImGuiWindowFlags::MINIMAL);
        Planar::Engine::UI::ImGui::text("Select Project");

        if (Planar::Engine::UI::ImGui::button("Create Project"))
        {
            std::wcout <<
                Planar::Engine::Core::FileSystem::SelectFolderDialog();
        }
    }
}
