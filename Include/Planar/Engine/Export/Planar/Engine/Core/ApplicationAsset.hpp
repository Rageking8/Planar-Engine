#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Math/Size2D.hpp"
#include "Planar/Engine/Graphics/SupportedGraphicsAPI.hpp"

struct Size2Di;

PLANAR_EXPORT_DECLARE_CONSTRUCT_DESTRUCT(
    Planar_Engine_Core_ApplicationAsset)

PLANAR_EXPORT_DECLARE_HANDLE_FUNCTION(
    Planar_Engine_Core_ApplicationAsset_load, void,
    const char* asset_string)

PLANAR_EXPORT_DECLARE_HANDLE_FUNCTION(
    Planar_Engine_Core_ApplicationAsset_get_window_name, const char*)
PLANAR_EXPORT_DECLARE_HANDLE_FUNCTION(
    Planar_Engine_Core_ApplicationAsset_get_window_size, Size2Di)
PLANAR_EXPORT_DECLARE_HANDLE_FUNCTION(
    Planar_Engine_Core_ApplicationAsset_get_maximize_window, bool)
PLANAR_EXPORT_DECLARE_HANDLE_FUNCTION(
    Planar_Engine_Core_ApplicationAsset_get_graphics_api,
    Planar::Engine::Graphics::SupportedGraphicsAPIBacking)
