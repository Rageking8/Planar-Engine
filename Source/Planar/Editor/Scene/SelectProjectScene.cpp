#include "Planar/Editor/Scene/SelectProjectScene.hpp"
#include "Planar/Editor/Project/Project.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"
#include "Planar/Engine/UI/ImGui/Window/WindowFlags.hpp"

#include <functional>

namespace Planar::Editor::Scene
{
    SelectProjectScene::SelectProjectScene() :
        open_project_button("Open Project"),
        project_name_input("Project Name"),
        project_description_input("Description"),
        project_gitignore_checkbox("Create .gitignore", true),
        create_project_button("Create Project"),
        pending_open_project{}, pending_create_project{},
        loading_mode{}
    {

    }

    void SelectProjectScene::init()
    {
        using namespace Planar::Engine::UI;
        using namespace Planar::Engine::Core::Utils::EnumClass;

        main_window.set("Select Project",
            ImGui::Window::WindowFlags::FIT_TO_WINDOW |
            ImGui::Window::WindowFlags::MINIMAL |
            ImGui::Window::WindowFlags::NO_BACKGROUND |
            ImGui::Window::WindowFlags::NO_STORE_INI);
        main_window.set_padding({ { 24.f, 0.f } });
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

        ImGui::Core::Cursor::set_y(24.f);
        ImGui::text("Select Project");

        ImGui::newline();

        open_project_button.render();
        if (!loading_mode && open_project_button.is_clicked())
        {
            pending_open_project = true;
        }

        ImGui::newline(2);

        project_name_input.render();
        project_description_input.render();
        project_gitignore_checkbox.render();

        create_project_button.render();
        if (!loading_mode && create_project_button.is_clicked())
        {
            pending_create_project = true;
        }

        if (loading_mode)
        {
            ImGui::Core::Cursor::set_y_bottom_viewport(
                -progress_bar.get_height() - 40.f);
            text_renderer.render_center_viewport(loading_text);

            ImGui::Core::Cursor::set_x(0.f);
            ImGui::Core::Cursor::set_y_bottom_viewport(
                -progress_bar.get_height());
            progress_bar.set_width(ImGui::get_window_size().width);
            progress_bar.render();
        }
    }

    void SelectProjectScene::open_project()
    {
        pending_open_project = false;

        if (!editor)
        {
            return;
        }

        if (editor->get_project().open_project())
        {
            editor->enter_editor();
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

        if (!editor)
        {
            return;
        }

        Project::Project& project = editor->get_project();

        enter_loading_mode(project.create_project_tasks(
            project_name, project_description, create_gitignore));

        if (project.create_project(project_name,
            project_description, create_gitignore,
            { std::bind(&SelectProjectScene::load_progress_callback, this,
            std::placeholders::_1, std::placeholders::_2) }) &&
            editor)
        {
            editor->enter_editor();
        }

        loading_mode = false;
    }

    void SelectProjectScene::enter_loading_mode(unsigned max)
    {
        loading_mode = true;
        progress_bar.set_value(0);
        progress_bar.set_max(max);
        loading_text.clear();
    }

    void SelectProjectScene::load_progress_callback(unsigned amount,
        const std::string& text)
    {
        progress_bar.increment(amount);

        if (amount == 0)
        {
            loading_text = text;
        }

        if (editor)
        {
            editor->render_single_frame(
                std::bind(&SelectProjectScene::render, this));
        }
    }
}
