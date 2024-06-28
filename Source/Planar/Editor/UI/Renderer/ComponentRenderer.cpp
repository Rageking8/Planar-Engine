#include "Planar/Editor/UI/Renderer/ComponentRenderer.hpp"
#include "Planar/Editor/UI/Element/Transform2D.hpp"

namespace Planar::Editor::UI::Renderer
{
    ComponentRenderer::ComponentRenderer()
    {

    }

    void ComponentRenderer::render(
        Engine::Component::ComponentType type)
    {
        reset_component_map();

        std::unique_ptr<Element::Component>& component =
            find_free_or_create_component(type);
        component->render();
    }

    void ComponentRenderer::reset_component_map()
    {
        for (auto& i : component_map)
        {
            for (auto& j : i.second)
            {
                j.in_use = false;
            }
        }
    }

    std::unique_ptr<Element::Component>&
        ComponentRenderer::find_free_or_create_component(
        Engine::Component::ComponentType type)
    {
        for (auto& i : component_map[type])
        {
            if (!i.in_use)
            {
                i.in_use = true;

                return i.component;
            }
        }

        switch (type)
        {
        case Engine::Component::ComponentType::Transform2D:
            component_map[type].emplace_back(true,
                std::make_unique<Element::Transform2D>());
            break;
        }

        return component_map[type].back().component;
    }
}
