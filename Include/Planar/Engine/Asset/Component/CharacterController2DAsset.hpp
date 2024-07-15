#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Asset/Component/Core/ComponentAsset.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"
#include "Planar/Engine/Asset/Component/Mixin/Active.hpp"

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(Component, CharacterController2D)

namespace Planar::Engine::Asset::Component
{
    class PLANAR_API CharacterController2DAsset :
        public Core::ComponentAsset<
        Engine::Component::CharacterController2D, Mixin::Active>
    {
    public:
        CharacterController2DAsset();

        PLANAR_DECLARE_GET_SET(float, speed)

    private:
        virtual void load_impl(
            Engine::Component::CharacterController2D& character_controller)
            override;
    };
}
