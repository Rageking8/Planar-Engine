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
    class PLANAR_API Camera2D :
        public Component<Camera2D, Asset::Component::Camera2DAsset>
    {
    public:
        PLANAR_DEFINE_COMPONENT(Camera2D)

        Camera2D(GameObject::GameObject* parent,
            bool generate_guid = true);

        bool get_active() const;
        void set_active(bool new_active);

    private:
        bool active;

        virtual void load_impl(YAML::Node node) override;
    };
}
