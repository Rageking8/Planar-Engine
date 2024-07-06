#pragma once

#include "Planar/Editor/UI/Element/Component/ComponentBase.hpp"
#include "Planar/Engine/Component/Core/ComponentType.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <vector>
#include <memory>
#include <unordered_map>

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(GameObject, GameObject)

namespace Planar::Editor::UI::Container
{
    class ComponentStore
    {
    public:
        struct Item
        {
            bool flag;
            std::unique_ptr<Element::Component::ComponentBase>
                component;
        };

        ComponentStore();

        void reset_all_item_flag();

        void update_items(Engine::GameObject::GameObject& game_object);
        bool write_components(Engine::GameObject::GameObject& game_object);

        Item& get_item(Engine::Component::Core::ComponentType type,
            bool create_if_needed = false);

    private:
        std::unordered_map<Engine::Component::Core::ComponentType,
            std::vector<Item>> store;

        template <typename ComponentT>
        Item& add_element();
    };
}
