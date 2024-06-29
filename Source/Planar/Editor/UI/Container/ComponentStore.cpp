#include "Planar/Editor/UI/Container/ComponentStore.hpp"
#include "Planar/Editor/UI/Element/Transform2D.hpp"
#include "Planar/Engine/GameObject/GameObject.hpp"
#include "Planar/Engine/Component/Component.hpp"
#include "Planar/Engine/Core/Utils/Checks/Assert.hpp"
#include "Planar/Engine/Core/Utils/Checks/Fatal.hpp"

namespace Planar::Editor::UI::Container
{
    ComponentStore::ComponentStore()
    {

    }

    void ComponentStore::reset_all_item_flag()
    {
        for (auto& item_vector_pair : store)
        {
            for (auto& item : item_vector_pair.second)
            {
                item.flag = false;
            }
        }
    }

    void ComponentStore::update_items(
        Engine::GameObject::GameObject& game_object)
    {
        reset_all_item_flag();

        for (auto& component : game_object.get_components())
        {
            Item& item = get_item(component->get_type(), true);

            item.component->set(component);
        }
    }

    ComponentStore::Item& ComponentStore::get_item(
        Engine::Component::ComponentType type, bool create_if_needed)
    {
        for (auto& item : store[type])
        {
            if (!item.flag)
            {
                item.flag = true;

                return item;
            }
        }

        PLANAR_ASSERT(create_if_needed,
            "Unable to create since `create_if_needed` is `false`");

        switch (type)
        {
        case Engine::Component::ComponentType::Transform2D:
            return store[type].emplace_back(true,
                std::make_unique<Element::Transform2D>());
        }

        PLANAR_FATAL("Unsupported `type`");
    }
}
