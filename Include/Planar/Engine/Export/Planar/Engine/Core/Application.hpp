#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Math/Size2D.hpp"
#include "Planar/Engine/Graphics/SupportedGraphicsAPI.hpp"

PLANAR_EXPORT_DECLARE_CONSTRUCT(Planar_Engine_Core_Application,
    const char* window_name, Planar::Engine::Math::Size2Di window_size,
    bool maximize, Planar::Engine::Graphics::SupportedGraphicsAPI
    graphics_api)
PLANAR_EXPORT_DECLARE_DESTRUCT(Planar_Engine_Core_Application)

PLANAR_EXPORT_DECLARE_HANDLE_FUNCTION(Planar_Engine_Core_Application_init,
    bool)
PLANAR_EXPORT_DECLARE_HANDLE_FUNCTION(Planar_Engine_Core_Application_run,
    void)
PLANAR_EXPORT_DECLARE_HANDLE_FUNCTION(
    Planar_Engine_Core_Application_load_scene, void, void* scene)
PLANAR_EXPORT_DECLARE_HANDLE_FUNCTION(
    Planar_Engine_Core_Application_get_asset_database, void*)
