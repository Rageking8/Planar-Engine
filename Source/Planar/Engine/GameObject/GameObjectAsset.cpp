#include "Planar/Engine/GameObject/GameObjectAsset.hpp"
#include "Planar/Engine/GameObject/GameObject.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

namespace Planar::Engine::GameObject
{
    GameObjectAsset::GameObjectAsset()
    {

    }

    void GameObjectAsset::load(YAML::Node node)
    {
        *asset = node;
    }

    void GameObjectAsset::load(GameObject& game_object)
    {
        clear();
        get("Name") = game_object.get_name();
        get("GUID") = game_object.get_guid();
        get("Children") = YAML::Node();
    }

    std::string GameObjectAsset::get_name() const
    {
        return get_scalar("Name");
    }

    std::string GameObjectAsset::get_guid() const
    {
        return get_scalar("GUID");
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

    YAML::Node GameObjectAsset::get_target() const
    {
        return (is_null() || is_sequence()) ?
            *asset : get("Children");
    }
}
