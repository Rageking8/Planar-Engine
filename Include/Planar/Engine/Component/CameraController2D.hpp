#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Math/Size2D.hpp"
#include "Planar/Engine/Component/Core/Component.hpp"
#include "Planar/Engine/Component/Core/ComponentMacros.hpp"
#include "Planar/Engine/Component/Mixin/Active.hpp"
#include "Planar/Engine/Asset/Component/CameraController2DAsset.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>

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

        PLANAR_DECLARE_GET_SET(std::string, mode)
        PLANAR_DECLARE_GET_SET(Math::Size2Df, horizontal_speed)
        PLANAR_DECLARE_GET_SET(Math::Size2Df, vertical_speed)
        PLANAR_DECLARE_GET_SET(std::string, tracked_transform)
        PLANAR_DECLARE_GET_SET(float, horizontal_lerp)
        PLANAR_DECLARE_GET_SET(float, vertical_lerp)

    private:
        std::string mode;
        Math::Size2Df horizontal_speed;
        Math::Size2Df vertical_speed;
        std::string tracked_transform;
        float horizontal_lerp;
        float vertical_lerp;

        virtual void load_impl() override;

        virtual void update_impl() override;
    };
}
