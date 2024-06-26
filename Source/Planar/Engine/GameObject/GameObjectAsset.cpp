#include "Planar/Engine/GameObject/GameObjectAsset.hpp"
#include "Planar/Engine/GameObject/GameObject.hpp"

namespace Planar::Engine::GameObject
{
    GameObjectAsset::GameObjectAsset()
    {

    }

    void GameObjectAsset::load(YAML::Node node)
    {
        asset = node;
    }

    void GameObjectAsset::load(GameObject& game_object)
    {
        asset = YAML::Node();
        asset["Name"] = game_object.get_name();
        asset["GUID"] = game_object.get_guid();
        asset["Children"] = YAML::Node();
    }

    std::string GameObjectAsset::get_name() const
    {
        return asset["Name"].Scalar();
    }

    std::string GameObjectAsset::get_guid() const
    {
        return asset["GUID"].Scalar();
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
        return (asset.IsNull() || asset.IsSequence()) ?
            asset : asset["Children"];
    }
}
