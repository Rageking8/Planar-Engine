#include "Planar/Engine/GameObject/GameObjectAsset.hpp"
#include "Planar/Engine/GameObject/GameObject.hpp"
#include "Planar/Engine/Core/Utils/Checks/Assert.hpp"
#include "Planar/Engine/Component/Core/ComponentBase.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

namespace Planar::Engine::GameObject
{
    GameObjectAsset::GameObjectAsset()
    {

    }

    void GameObjectAsset::load(GameObject& game_object)
    {
        clear();
        set_name(game_object.get_name());
        set_value("GUID", game_object.get_guid());
        set_active(game_object.active_self());

        for (const auto& component : game_object.get_components())
        {
            add_component(component->get_node());
        }

        get("Children") = YAML::Node();
    }

    void GameObjectAsset::set_name(const std::string& new_name)
    {
        set_value("Name", new_name);
    }

    bool GameObjectAsset::get_active() const
    {
        return get_value<bool>("Active");
    }

    void GameObjectAsset::set_active(bool new_active)
    {
        set_value("Active", new_active);
    }

    void GameObjectAsset::add_child(YAML::Node child)
    {
        get_children().push_back(child);
    }

    void GameObjectAsset::remove_child(std::size_t index)
    {
        YAML::Node children = get_children();
        children.remove(index);

        if (children.size() == 0)
        {
            children = YAML::Node();
        }
    }

    void GameObjectAsset::add_component(YAML::Node component)
    {
        get_components().push_back(component);
    }

    void GameObjectAsset::remove_component(std::size_t index)
    {
        YAML::Node components = get_components();
        components.remove(index);

        PLANAR_ASSERT(components.size() > 0,
            "There should always be at least 1 component");
    }

    YAML::Node GameObjectAsset::get_children() const
    {
        return (is_null() || is_sequence()) ?
            *asset : get("Children");
    }

    YAML::Node GameObjectAsset::get_components() const
    {
        PLANAR_ASSERT((!is_null() && !is_sequence()),
            "This asset is not allowed to have components");

        return get("Components");
    }
}
