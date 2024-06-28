#pragma once

#include "Planar/Editor/UI/Element/Component.hpp"
#include "Planar/Engine/Component/ComponentType.hpp"

#include <vector>
#include <memory>
#include <unordered_map>

namespace Planar::Editor::UI::Renderer
{
    class ComponentRenderer
    {
    public:
        struct ComponentItem
        {
            bool in_use;
            std::unique_ptr<Element::Component> component;
        };

        ComponentRenderer();

        void render(Engine::Component::ComponentType type);

    private:
        std::unordered_map<Engine::Component::ComponentType,
            std::vector<ComponentItem>> component_map;

        void reset_component_map();
        std::unique_ptr<Element::Component>&
            find_free_or_create_component(
            Engine::Component::ComponentType type);
    };
}
