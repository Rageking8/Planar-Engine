#include "Planar/Editor/Scene/SelectProjectScene.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/ImGuiWindow.hpp"
#include "Planar/Engine/UI/ImGui/ImGuiWindowFlags.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"

#include <iostream>

namespace Planar::Editor::Scene
{
    void SelectProjectScene::init()
    {
        Planar::Engine::UI::ImGui::scale_ui(3);
    }

    void SelectProjectScene::render()
    {
        using namespace Planar::Engine::UI;
        using namespace Planar::Engine::Core::Utils;

        ImGui::ImGuiWindow window(
            "Select Project",
            ImGui::ImGuiWindowFlags::FIT_TO_WINDOW |
            ImGui::ImGuiWindowFlags::MINIMAL);

        ImGui::text("Select Project");

        ImGui::newline();

        if (ImGui::button("Open Project"))
        {

        }

        ImGui::newline();

        if (ImGui::button("Create Project"))
        {
            std::wcout <<
                Planar::Engine::Core::FileSystem::SelectFolderDialog();
        }
    }
}
