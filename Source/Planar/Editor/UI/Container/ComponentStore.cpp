#include "Planar/Editor/UI/Container/ComponentStore.hpp"
#include "Planar/Editor/UI/Element/Transform2D.hpp"
#include "Planar/Engine/Component/Transform2D.hpp"
#include "Planar/Engine/GameObject/GameObject.hpp"
#include "Planar/Engine/Component/Component.hpp"
#include "Planar/Engine/Core/Utils/Checks/Assert.hpp"
#include "Planar/Engine/Core/Utils/Checks/Fatal.hpp"
#include "Planar/Engine/Core/Utils/Cast/Cast.hpp"

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
            const Engine::Component::ComponentType type =
                component->get_type();
            Item& item = get_item(type, true);

            switch (type)
            {
            case Engine::Component::ComponentType::Transform2D:
                Element::Transform2D* element =
                    Engine::Core::Utils::Cast::unique_ptr_downcast
                    <Element::Transform2D>(item.component);
                Engine::Component::Transform2D* transform =
                    Engine::Core::Utils::Cast::shared_ptr_downcast
                    <Engine::Component::Transform2D>(component);
                element->set_position(transform->get_position());
                element->set_rotation(transform->get_rotation());
                break;

            default:
                PLANAR_FATAL("Unsupported `type`");
                break;
            }
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
