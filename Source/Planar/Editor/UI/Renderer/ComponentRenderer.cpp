#include "Planar/Editor/UI/Renderer/ComponentRenderer.hpp"
#include "Planar/Editor/UI/Container/ComponentStore.hpp"
#include "Planar/Editor/Core/Editor.hpp"
#include "Planar/Engine/UI/ImGui/Menu/Menu.hpp"
#include "Planar/Engine/UI/ImGui/Menu/ContextMenu.hpp"
#include "Planar/Engine/GameObject/GameObject.hpp"
#include "Planar/Engine/Component/Core/ComponentBase.hpp"

namespace Planar::Editor::UI::Renderer
{
    ComponentRenderer::ComponentRenderer(Core::Editor* editor) :
        editor{ editor }, context_menu_active{}
    {

    }

    void ComponentRenderer::render(
        Container::ComponentStore& component_store,
        std::shared_ptr<Engine::GameObject::GameObject> game_object,
        Engine::UI::ImGui::Menu::ContextMenu* context_menu)
    {
        if (context_menu_active)
        {
            context_menu_active = context_menu->render({}, { false });
        }

        component_store.reset_all_item_flag();

        for (auto& component : game_object->get_components())
        {
            component_store.get_item(component->get_type()).
                component->render([=, this](std::string guid)
                    {
                        render_context_menu(game_object, context_menu,
                            guid);
                    });
        }
    }

    void ComponentRenderer::render_context_menu(
        std::shared_ptr<Engine::GameObject::GameObject> game_object,
        Engine::UI::ImGui::Menu::ContextMenu* context_menu,
        std::string guid)
    {
        using namespace Engine::UI;

        if (context_menu_active)
        {
            return;
        }

        context_menu->set_content([=]
            {
                if (ImGui::Menu::menu_item("Remove Component"))
                {
                    game_object->remove_component(guid);

                    editor->set_dirty();

                    return true;
                }

                return false;
            });

        if (context_menu->render({}, { true }))
        {
            context_menu_active = true;
        }
    }
}
