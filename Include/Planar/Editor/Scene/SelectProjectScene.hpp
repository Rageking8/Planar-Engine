#pragma once

#include "Planar/Engine/Scene/Scene.hpp"
#include "Planar/Engine/UI/ImGui/ImGuiInputField.hpp"

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

    private:
        Planar::Engine::UI::ImGui::ImGuiInputField project_name_input;
        Planar::Engine::UI::ImGui::ImGuiInputField project_description_input;

        bool pending_open_project;
        bool pending_create_project;

        std::function<void()> editor_enter_callback;

        void open_project();
        void create_project();
    };
}
