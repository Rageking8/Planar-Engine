#include "Planar/Editor/Scene/SelectProjectScene.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/ImGuiWindow.hpp"
#include "Planar/Engine/UI/ImGui/ImGuiWindowFlags.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"
#include "Planar/Engine/Asset/Asset.hpp"

#include <iostream>
#include <filesystem>

namespace Planar::Editor::Scene
{
    SelectProjectScene::SelectProjectScene() :
        project_name_input("Project Name"),
        project_description_input("Description")
    {

    }

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
            open_project();
        }

        ImGui::newline();

        project_name_input.render();
        project_description_input.render();
        
        if (ImGui::button("Create Project"))
        {
            create_project();
        }
    }

    void SelectProjectScene::open_project()
    {
        std::wstring directory =
            Planar::Engine::Core::FileSystem::SelectFolderDialog();

        if (directory.empty())
        {
            std::cout << "Invalid directory\n";

            return;
        }

        if (!std::filesystem::exists(directory + L"/Project.planar"))
        {
            std::cout << "No project file found\n";
            
            return;
        }
    }

    void SelectProjectScene::create_project()
    {
        const std::string& project_name = project_name_input.get_text();
        const std::string& project_description =
            project_description_input.get_text();

        if (project_name.empty())
        {
            std::cout << "Project name cannot be empty\n";

            return;
        }

        std::wstring directory =
            Planar::Engine::Core::FileSystem::SelectFolderDialog();

        if (directory.empty())
        {
            std::cout << "Invalid directory\n";

            return;
        }

        Planar::Engine::Asset::create_project_file(project_name,
            project_description, directory);
    }
}
