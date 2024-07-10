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
        get_children().push_back(child);
    }

    void GameObjectAsset::remove_child(std::size_t index)
    {
        YAML::Node target = get_children();
        target.remove(index);

        if (target.size() == 0)
        {
            target = YAML::Node();
        }
    }

    void GameObjectAsset::add_component(YAML::Node component)
    {
        get_components().push_back(component);
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
