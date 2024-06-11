#pragma once

#include "Planar/Engine/Scene/Scene.hpp"
#include "Planar/Engine/Core/Application.hpp"
#include "Planar/Editor/Project/Project.hpp"

#include <memory>

namespace Planar::Editor::Core
{
    class Editor : public Engine::Core::Application
    {
    public:
        Editor();

        virtual bool init() override;

        void enter_editor();

    private:
        Project::Project project;
        std::unique_ptr<Engine::Scene::Scene> current_scene;
    };
}
