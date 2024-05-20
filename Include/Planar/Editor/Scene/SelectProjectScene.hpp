#pragma once

#include "Planar/Engine/Scene/Scene.hpp"
#include "Planar/Engine/UI/ImGui/Window/Window.hpp"
#include "Planar/Engine/UI/ImGui/Element/InputField.hpp"
#include "Planar/Engine/UI/ImGui/Element/Checkbox.hpp"
#include "Planar/Engine/UI/ImGui/Element/Button.hpp"
#include "Planar/Editor/Project/Project.hpp"

#include <functional>

namespace Planar::Editor::Scene
{
    class SelectProjectScene :
        public Planar::Engine::Scene::Scene
    {
    public:
        SelectProjectScene();

        virtual void init() override;
        virtual void update() override;
        virtual void render() override;

        void set_editor_enter_callback(std::function<void()> callback);

        void set_project(Planar::Editor::Project::Project* new_project);

    private:
        Planar::Engine::UI::ImGui::Element::Button
            open_project_button;
        Planar::Engine::UI::ImGui::Element::InputField
            project_name_input;
        Planar::Engine::UI::ImGui::Element::InputField
            project_description_input;
        Planar::Engine::UI::ImGui::Element::Checkbox
            project_gitignore_checkbox;
        Planar::Engine::UI::ImGui::Element::Button
            create_project_button;

        bool pending_open_project;
        bool pending_create_project;

        Planar::Engine::UI::ImGui::Window::Window main_window;

        std::function<void()> editor_enter_callback;

        Planar::Editor::Project::Project* project;

        void open_project();
        void create_project();
    };
}
