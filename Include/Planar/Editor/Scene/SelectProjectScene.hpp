#pragma once

#include "Planar/Editor/Scene/Scene.hpp"
#include "Planar/Engine/UI/ImGui/Window/Window.hpp"
#include "Planar/Engine/UI/ImGui/Element/InputField.hpp"
#include "Planar/Engine/UI/ImGui/Element/Checkbox.hpp"
#include "Planar/Engine/UI/ImGui/Element/Button.hpp"
#include "Planar/Editor/UI/Element/ProgressDisplay.hpp"

namespace Planar::Editor::Scene
{
    class SelectProjectScene : public Scene
    {
    public:
        SelectProjectScene();

        virtual void init() override;
        virtual void update() override;
        virtual void render() override;

    private:
        Engine::UI::ImGui::Element::Button open_project_button;
        Engine::UI::ImGui::Element::InputField project_name_input;
        Engine::UI::ImGui::Element::InputField project_description_input;
        Engine::UI::ImGui::Element::Checkbox project_gitignore_checkbox;
        Engine::UI::ImGui::Element::Button create_project_button;
        UI::Element::ProgressDisplay progress_display;

        bool pending_open_project;
        bool pending_create_project;

        bool loading_mode;

        Engine::UI::ImGui::Window::Window main_window;

        void open_project();
        void create_project();

        void enter_loading_mode(unsigned max);
        void load_progress_callback(unsigned amount,
            const std::string& text);
    };
}
