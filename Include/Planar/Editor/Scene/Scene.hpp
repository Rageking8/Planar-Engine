#pragma once

#include "Planar/Engine/Scene/Scene.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

PLANAR_FORWARD_DECLARE_CLASS(Editor::Core, Editor)

namespace Planar::Editor::Scene
{
    class Scene : public Engine::Scene::Scene
    {
    public:
        Scene(Core::Editor* editor);
        virtual ~Scene() = 0;

    protected:
        Core::Editor* editor;
    };
}
