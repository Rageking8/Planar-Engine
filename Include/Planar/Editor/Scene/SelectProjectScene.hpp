#pragma once

#include "Planar/Engine/Scene/Scene.hpp"
#include "Planar/Engine/UI/ImGui/ImGuiInputField.hpp"

namespace Planar::Editor::Scene
{
    class SelectProjectScene :
        public Planar::Engine::Scene::Scene
    {
    public:
        SelectProjectScene();

        virtual void init() override;
        virtual void render() override;

    private:
        Planar::Engine::UI::ImGui::ImGuiInputField project_name_input;
        Planar::Engine::UI::ImGui::ImGuiInputField project_description_input;

        void open_project();
        void create_project();
    };
}
