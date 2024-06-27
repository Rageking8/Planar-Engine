#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Asset/Asset.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>
#include <cstddef>

PLANAR_FORWARD_DECLARE_CLASS(YAML, Node)
PLANAR_ENGINE_FORWARD_DECLARE_CLASS(GameObject, GameObject)

namespace Planar::Engine::GameObject
{
    class PLANAR_API GameObjectAsset : public Asset::Asset
    {
    public:
        GameObjectAsset();

        void load(YAML::Node node);
        void load(GameObject& game_object);

        std::string get_name() const;
        std::string get_guid() const;

        void add_child(YAML::Node child);
        void remove_child(std::size_t index);

    private:
        YAML::Node get_target() const;
    };
}
