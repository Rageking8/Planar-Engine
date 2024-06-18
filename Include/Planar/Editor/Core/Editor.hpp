#pragma once

#include "Planar/Engine/Scene/Scene.hpp"
#include "Planar/Engine/Core/Application.hpp"
#include "Planar/Editor/Project/Project.hpp"

#include <string>
#include <memory>

namespace Planar::Editor::Core
{
    class Editor : public Engine::Core::Application
    {
    public:
        Editor();

        virtual bool init() override;

        void enter_editor();

        void change_scene(
            std::unique_ptr<Engine::Scene::Scene> new_scene);
        void update_window_name(const std::string& scene_name = "",
            bool show_asterisk = false);

        void set_window_asterisk(bool show);

        Project::Project& get_project();
        std::unique_ptr<Engine::Scene::Scene>& get_current_scene();

    private:
        Project::Project project;
        std::unique_ptr<Engine::Scene::Scene> current_scene;
    };
}
