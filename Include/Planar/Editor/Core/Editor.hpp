#pragma once

#include "Planar/Engine/Scene/Scene.hpp"
#include "Planar/Engine/Core/Application.hpp"
#include "Planar/Editor/Project/Project.hpp"
#include "Planar/Editor/Core/Save/SaveHandler.hpp"
#include "Planar/Editor/Core/Select/SelectHandler.hpp"

#include <string>
#include <memory>
#include <functional>

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

        void add_save_callback(const std::string& name,
            const std::function<void()>& save_callback);

        void set_dirty();
        void save_all();

        Select::SelectHandler& get_select_handler();

    private:
        Project::Project project;
        std::unique_ptr<Engine::Scene::Scene> current_scene;
        Save::SaveHandler save_handler;
        Select::SelectHandler select_handler;
    };
}
