#include "Planar/Engine/GameObject/GameObjectAsset.hpp"
#include "Planar/Engine/GameObject/GameObject.hpp"
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

        for (const auto& component : game_object.get_components())
        {
            add_component(component->get_node());
        }

        get("Children") = YAML::Node();
    }

    std::string GameObjectAsset::get_name() const
    {
        return get_value<std::string>("Name");
    }

    void GameObjectAsset::set_name(const std::string& new_name)
    {
        set_value("Name", new_name);
    }

    std::string GameObjectAsset::get_guid() const
    {
        return get_value<std::string>("GUID");
    }

    void GameObjectAsset::add_child(YAML::Node child)
    {
        get_target().push_back(child);
    }

    void GameObjectAsset::remove_child(std::size_t index)
    {
        YAML::Node target = get_target();
        target.remove(index);

        if (target.size() == 0)
        {
            target = YAML::Node();
        }
    }

    void GameObjectAsset::add_component(YAML::Node component)
    {
        get("Components").push_back(component);
    }

    YAML::Node GameObjectAsset::get_target() const
    {
        return (is_null() || is_sequence()) ?
            *asset : get("Children");
    }
}
