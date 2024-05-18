#pragma once

#include "Planar/Engine/Core/Application.hpp"
#include "Planar/Editor/Project/Project.hpp"

namespace Planar::Editor::Core
{
    class Editor : public Planar::Engine::Core::Application
    {
    public:
        Editor();

        virtual bool init() override;

        void enter_editor();

        void load_scripting();

    private:
        Planar::Editor::Project::Project project;
    };
}
