#include "Planar/Engine/Export/Planar/Engine/Core/ApplicationAsset.hpp"
#include "Planar/Engine/Core/ApplicationAsset.hpp"

#include <string>

struct Size2Di
{
    int width;
    int height;
};

PLANAR_EXPORT_DEFINE_CONSTRUCT_DESTRUCT(
    Planar_Engine_Core_ApplicationAsset,
    Planar::Engine::Core::ApplicationAsset)

PLANAR_EXPORT_DEFINE_HANDLE_FUNCTION(Planar_Engine_Core_ApplicationAsset,
    load, const char* asset_string, std::string(asset_string),
    Planar::Engine::Core::ApplicationAsset)

extern "C" __declspec(dllexport) const char*
Planar_Engine_Core_ApplicationAsset_get_window_name(void* handle)
{
    return static_cast<Planar::Engine::Core::ApplicationAsset*>(handle)->
        get_window_name().c_str();
}
extern "C" __declspec(dllexport) Size2Di
Planar_Engine_Core_ApplicationAsset_get_window_size(void* handle)
{
    const Planar::Engine::Math::Size2Di size =
        static_cast<Planar::Engine::Core::ApplicationAsset*>(handle)->
        get_window_size();

    return { size.width, size.height };
}
PLANAR_EXPORT_DEFINE_HANDLE_FUNCTION(Planar_Engine_Core_ApplicationAsset,
    get_maximize_window, bool, Planar::Engine::Core::ApplicationAsset)
PLANAR_EXPORT_DEFINE_HANDLE_FUNCTION(Planar_Engine_Core_ApplicationAsset,
    get_graphics_api, Planar::Engine::Graphics::SupportedGraphicsAPIBacking,
    Planar::Engine::Core::ApplicationAsset)
