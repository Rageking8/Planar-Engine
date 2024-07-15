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
    PLANAR_DEFINE_COMPONENT_ASSET_GET_SET_VALUE(CharacterController2D,
        bool, enable_x_flip, EnableXFlip)
    PLANAR_DEFINE_COMPONENT_ASSET_GET_SET_VALUE(CharacterController2D,
        bool, inverse_x_flip, InverseXFlip)

    void CharacterController2DAsset::load_impl(
        Engine::Component::CharacterController2D& character_controller)
    {
        set_speed(character_controller.get_speed());
        set_enable_x_flip(character_controller.get_enable_x_flip());
        set_inverse_x_flip(character_controller.get_inverse_x_flip());
    }
}
