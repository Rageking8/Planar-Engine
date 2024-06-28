#pragma once

#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

PLANAR_EDITOR_FORWARD_DECLARE_CLASS(UI::Container, ComponentStore)
PLANAR_ENGINE_FORWARD_DECLARE_CLASS(GameObject, GameObject)

namespace Planar::Editor::UI::Renderer
{
    class ComponentRenderer
    {
    public:
        ComponentRenderer();

        void render(Container::ComponentStore& component_store,
            Engine::GameObject::GameObject& game_object);
    };
}
