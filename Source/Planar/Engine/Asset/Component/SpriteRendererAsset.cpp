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

    void SpriteRendererAsset::load_impl(
        Engine::Component::SpriteRenderer& sprite_renderer)
    {
        set_sprite(sprite_renderer.get_sprite());
    }
}
