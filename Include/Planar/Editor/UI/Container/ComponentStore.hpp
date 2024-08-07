#pragma once

#include "Planar/Editor/UI/Element/Component/Core/ComponentBase.hpp"
#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"
#include "Planar/Engine/Component/Core/ComponentType.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <vector>
#include <memory>
#include <unordered_map>

PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Core, Editor)
PLANAR_ENGINE_FORWARD_DECLARE_CLASS(GameObject, GameObject)

namespace Planar::Editor::UI::Container
{
    class ComponentStore
    {
    public:
        struct Item
        {
            bool flag;
            std::unique_ptr<Element::Component::Core::ComponentBase>
                component;
        };

        ComponentStore(Core::Editor* editor);

        void reset_all_item_flag();

        void update_items(Engine::GameObject::GameObject& game_object);
        bool write_components(Engine::GameObject::GameObject& game_object);

        Item& get_item(Engine::Component::Core::ComponentType type,
            bool create_if_needed = false);

    private:
        Core::Editor* editor;
        std::unordered_map<Engine::Component::Core::ComponentType,
            std::vector<Item>> store;

        template <typename ComponentT>
        Item& add_element();
    };
}
