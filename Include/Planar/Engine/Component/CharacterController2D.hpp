#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Component/Core/Component.hpp"
#include "Planar/Engine/Component/Core/ComponentMacros.hpp"
#include "Planar/Engine/Component/Mixin/Active.hpp"
#include "Planar/Engine/Asset/Component/CharacterController2DAsset.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

PLANAR_ENGINE_FORWARD_DECLARE_CLASS(GameObject, GameObject)

namespace Planar::Engine::Component
{
    class PLANAR_API CharacterController2D :
        public Core::Component<CharacterController2D,
        Asset::Component::CharacterController2DAsset, Mixin::Active>
    {
    public:
        PLANAR_DEFINE_COMPONENT(CharacterController2D)

        CharacterController2D(GameObject::GameObject* parent,
            bool generate_guid = true);

    private:
        virtual void load_impl() override;
    };
}
