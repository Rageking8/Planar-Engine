#include "Planar/Engine/Asset/Component/SpriteRendererAsset.hpp"
#include "Planar/Engine/Asset/Component/Core/ComponentAssetMacros.hpp"
#include "Planar/Engine/Component/SpriteRenderer.hpp"

namespace Planar::Engine::Asset::Component
{
    SpriteRendererAsset::SpriteRendererAsset()
    {

    }

    PLANAR_DEFINE_COMPONENT_ASSET_GET_SET_VALUE(SpriteRenderer,
        std::string, sprite, Sprite)
    PLANAR_DEFINE_COMPONENT_ASSET_GET_SET_VALUE(SpriteRenderer,
        bool, flip_x, FlipX)
    PLANAR_DEFINE_COMPONENT_ASSET_GET_SET_VALUE(SpriteRenderer,
        bool, flip_y, FlipY)
    PLANAR_DEFINE_COMPONENT_ASSET_GET_SET_FLOAT_2(SpriteRenderer,
        Math::Size2Df, tile_factor, TileFactor, X, Y)

    void SpriteRendererAsset::load_impl(
        Engine::Component::SpriteRenderer& sprite_renderer)
    {
        set_sprite(sprite_renderer.get_sprite());
        set_flip_x(sprite_renderer.get_flip_x());
        set_flip_y(sprite_renderer.get_flip_y());
        set_tile_factor(sprite_renderer.get_tile_factor());
    }
}
