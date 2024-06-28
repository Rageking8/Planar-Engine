#include "Planar/Editor/UI/Renderer/ComponentRenderer.hpp"
#include "Planar/Editor/UI/Container/ComponentStore.hpp"
#include "Planar/Engine/GameObject/GameObject.hpp"
#include "Planar/Engine/Component/Component.hpp"

namespace Planar::Editor::UI::Renderer
{
    ComponentRenderer::ComponentRenderer()
    {

    }

    void ComponentRenderer::render(
        Container::ComponentStore& component_store,
        Engine::GameObject::GameObject& game_object)
    {
        component_store.reset_all_item_flag();

        for (auto& component : game_object.get_components())
        {
            component_store.get_item(component->get_type()).
                component->render();
        }
    }
}
