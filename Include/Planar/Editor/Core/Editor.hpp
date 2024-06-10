#pragma once

#include "Planar/Engine/Core/Application.hpp"
#include "Planar/Editor/Project/Project.hpp"

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
    };
}
