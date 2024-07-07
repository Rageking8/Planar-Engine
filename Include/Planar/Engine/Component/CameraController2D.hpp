#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Math/Size2D.hpp"
#include "Planar/Engine/Component/Core/Component.hpp"
#include "Planar/Engine/Component/Core/ComponentMacros.hpp"
#include "Planar/Engine/Component/Mixin/Active.hpp"
#include "Planar/Engine/Asset/Component/CameraController2DAsset.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(GameObject, GameObject)

namespace Planar::Engine::Component
{
    class PLANAR_API CameraController2D :
        public Core::Component<CameraController2D,
        Asset::Component::CameraController2DAsset, Mixin::Active>
    {
    public:
        PLANAR_DEFINE_COMPONENT(CameraController2D)

        CameraController2D(GameObject::GameObject* parent,
            bool generate_guid = true);

        virtual void update() override;

        PLANAR_DECLARE_GET_SET(Math::Size2Df, horizontal_speed)
        PLANAR_DECLARE_GET_SET(Math::Size2Df, vertical_speed)

    private:
        Math::Size2Df horizontal_speed;
        Math::Size2Df vertical_speed;

        virtual void load_impl() override;
    };
}
