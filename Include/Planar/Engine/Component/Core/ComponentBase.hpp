#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Component/Core/ComponentType.hpp"
#include "Planar/Engine/Component/Core/ComponentMacros.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>
#include <memory>

PLANAR_FORWARD_DECLARE_CLASS(YAML, Node)
PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Asset, Asset)
PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Component, Transform2D)
PLANAR_ENGINE_FORWARD_DECLARE_CLASS(GameObject, GameObject)

namespace Planar::Engine::Component::Core
{
    class PLANAR_API ComponentBase
    {
    public:
        PLANAR_DEFINE_COMPONENT_TYPE_AND_NAME(ComponentBase)

        ComponentBase(GameObject::GameObject* parent,
            bool generate_guid = true);
        virtual ~ComponentBase();

        virtual ComponentType get_type() const = 0;

        virtual bool match(ComponentType other) const;

        virtual void update();

        std::string get_guid() const;
        void set_guid(const std::string& new_guid);

        GameObject::GameObject* get_parent() const;
        void set_parent(GameObject::GameObject* new_parent);

        std::shared_ptr<Transform2D> get_transform();

        virtual void load_asset() = 0;

        virtual const Asset::Asset& get_asset() const = 0;
        YAML::Node get_node() const;

    private:
        std::string guid;
        GameObject::GameObject* parent;
    };
}
