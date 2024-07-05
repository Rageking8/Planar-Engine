#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Component/Component.hpp"
#include "Planar/Engine/Component/ComponentMacros.hpp"
#include "Planar/Engine/Asset/Component/Camera2DAsset.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

PLANAR_FORWARD_DECLARE_CLASS(YAML, Node)
PLANAR_ENGINE_FORWARD_DECLARE_CLASS(GameObject, GameObject)

namespace Planar::Engine::Component
{
    class PLANAR_API Camera2D : public Component
    {
    public:
        PLANAR_DEFINE_COMPONENT(Camera2D)

        Camera2D(GameObject::GameObject* parent,
            bool generate_guid = true);

        void load(YAML::Node node);

        bool get_active() const;
        void set_active(bool new_active);

        virtual void load_asset() override;

        virtual const Asset::Component::Camera2DAsset& get_asset()
            const override;

    private:
        bool active;
        Asset::Component::Camera2DAsset asset;
    };
}
