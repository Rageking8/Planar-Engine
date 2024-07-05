#include "Planar/Editor/UI/Container/ComponentStore.hpp"
#include "Planar/Editor/UI/Element/Component/Transform2D.hpp"
#include "Planar/Editor/UI/Element/Component/Camera2D.hpp"
#include "Planar/Editor/UI/Element/Component/CameraController2D.hpp"
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

            item.component->set_values(component);
        }
    }

    bool ComponentStore::write_components(
        Engine::GameObject::GameObject& game_object)
    {
        bool written = false;

        reset_all_item_flag();

        for (auto& component : game_object.get_components())
        {
            Item& item = get_item(component->get_type());

            written |= item.component->write_values(component);
        }

        return written;
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
            return add_element<Element::Component::Transform2D>();

        case Engine::Component::ComponentType::Camera2D:
            return add_element<Element::Component::Camera2D>();

        case Engine::Component::ComponentType::CameraController2D:
            return add_element<Element::Component::CameraController2D>();
        }

        PLANAR_FATAL("Unsupported `type`");
    }

    template <typename ComponentT>
    ComponentStore::Item& ComponentStore::add_element()
    {
        return store[ComponentT::ComponentType::TYPE].
            emplace_back(true, std::make_unique<ComponentT>());
    }
}
