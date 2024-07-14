#pragma once

#include "Planar/Engine/Scene/Scene.hpp"
#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>

PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Core, Editor)

namespace Planar::Editor::Scene
{
    class Scene : public Engine::Scene::Scene
    {
    public:
        Scene(Core::Editor* editor, const std::string& name);
        virtual ~Scene() = 0;

        virtual std::string get_name() const override;

    protected:
        Core::Editor* editor;

    private:
        std::string name;
    };
}
