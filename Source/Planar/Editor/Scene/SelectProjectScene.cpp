#include "Planar/Editor/Scene/SelectProjectScene.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/ImGuiWindowFlags.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"
#include "Planar/Engine/Asset/Asset.hpp"

#include <iostream>
#include <filesystem>

namespace Planar::Editor::Scene
{
    SelectProjectScene::SelectProjectScene() :
        project_name_input("Project Name"),
        project_description_input("Description"),
        pending_open_project{}, pending_create_project{}
    {

    }

    void SelectProjectScene::init()
    {
        using namespace Planar::Engine::UI;
        using namespace Planar::Engine::Core::Utils;

        ImGui::scale_ui(3);

        main_window.set("Select Project",
            ImGui::ImGuiWindowFlags::FIT_TO_WINDOW |
            ImGui::ImGuiWindowFlags::MINIMAL |
            ImGui::ImGuiWindowFlags::NO_STORE_INI);
    }

    void SelectProjectScene::update()
    {
        if (pending_open_project)
        {
            open_project();

            return;
        }

        if (pending_create_project)
        {
            create_project();

            return;
        }
    }

    void SelectProjectScene::render()
    {
        using namespace Planar::Engine::UI;

        auto main_window_scope = main_window.render();

        ImGui::text("Select Project");

        ImGui::newline();

        if (ImGui::button("Open Project"))
        {
            pending_open_project = true;
        }

        ImGui::newline();

        project_name_input.render();
        project_description_input.render();
        
        if (ImGui::button("Create Project"))
        {
            pending_create_project = true;
        }
    }

    void SelectProjectScene::set_editor_enter_callback(
        std::function<void()> callback)
    {
        editor_enter_callback = callback;
    }

    void SelectProjectScene::open_project()
    {
        pending_open_project = false;

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

        if (editor_enter_callback)
        {
            editor_enter_callback();
        }
    }

    void SelectProjectScene::create_project()
    {
        pending_create_project = false;

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

        if (editor_enter_callback)
        {
            editor_enter_callback();
        }
    }
}
