#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

#include <cstddef>

PLANAR_EXPORT_DECLARE_HANDLE_FUNCTION(
    Planar_Engine_Asset_AssetDatabase_load_sprite,
    void, const char* name, const char* asset,
    const unsigned char* sprite, std::size_t length)
PLANAR_EXPORT_DECLARE_HANDLE_FUNCTION(
    Planar_Engine_Asset_AssetDatabase_load_audio,
    void, const char* name, const char* asset,
    const unsigned char* audio, std::size_t length)
