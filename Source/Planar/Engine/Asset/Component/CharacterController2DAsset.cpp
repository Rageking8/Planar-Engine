#include "Planar/Engine/Asset/Component/CharacterController2DAsset.hpp"
#include "Planar/Engine/Asset/Component/Core/ComponentAssetMacros.hpp"
#include "Planar/Engine/Component/CharacterController2D.hpp"

namespace Planar::Engine::Asset::Component
{
    CharacterController2DAsset::CharacterController2DAsset()
    {

    }

    PLANAR_DEFINE_COMPONENT_ASSET_GET_SET_VALUE(CharacterController2D,
        float, speed, Speed)

    void CharacterController2DAsset::load_impl(
        Engine::Component::CharacterController2D& character_controller)
    {
        set_speed(character_controller.get_speed());
    }
}
