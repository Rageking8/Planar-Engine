#include "Planar/Editor/Scene/SelectProjectScene.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Window/WindowFlags.hpp"

namespace Planar::Editor::Scene
{
    SelectProjectScene::SelectProjectScene() :
        open_project_button("Open Project"),
        project_name_input("Project Name"),
        project_description_input("Description"),
        project_gitignore_checkbox("Create .gitignore", true),
        create_project_button("Create Project"),
        pending_open_project{}, pending_create_project{},
        project{}
    {

    }

    void SelectProjectScene::init()
    {
        using namespace Planar::Engine::UI;
        using namespace Planar::Engine::Core::Utils::EnumClass;

        main_window.set("Select Project",
            ImGui::Window::WindowFlags::FIT_TO_WINDOW |
            ImGui::Window::WindowFlags::MINIMAL |
            ImGui::Window::WindowFlags::NO_STORE_INI);
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

        open_project_button.render();
        if (open_project_button.is_clicked())
        {
            pending_open_project = true;
        }

        ImGui::newline(2);

        project_name_input.render();
        project_description_input.render();
        project_gitignore_checkbox.render();

        create_project_button.render();
        if (create_project_button.is_clicked())
        {
            pending_create_project = true;
        }
    }

    void SelectProjectScene::set_editor_enter_callback(
        std::function<void()> callback)
    {
        editor_enter_callback = callback;
    }

    void SelectProjectScene::set_project(Planar::Editor::Project::Project*
        new_project)
    {
        project = new_project;
    }

    void SelectProjectScene::open_project()
    {
        pending_open_project = false;

        if (project && project->open_project() &&
            editor_enter_callback)
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
        const bool create_gitignore = project_gitignore_checkbox.
            get_value();

        if (project && project->create_project(project_name,
            project_description, create_gitignore) &&
            editor_enter_callback)
        {
            editor_enter_callback();
        }
    }
}
