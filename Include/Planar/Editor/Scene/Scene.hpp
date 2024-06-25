#pragma once

#include "Planar/Engine/Scene/Scene.hpp"
#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"

PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Core, Editor)

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
