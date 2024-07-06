#include "Planar/Engine/Core/Mixin/Mixin.hpp"

namespace Planar::Engine::Core::Mixin
{
    template <typename AssetT>
    inline Mixin<AssetT>::Mixin(AssetT* asset) : asset{ asset }
    {

    }
}
