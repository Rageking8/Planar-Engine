#pragma once

#include "Planar/Engine/Core/ExportMacros.hpp"

extern "C"
{
    PLANAR_API void* Planar_Engine_Core_Log_Logger_construct();
    PLANAR_API void Planar_Engine_Core_Log_Logger_destruct(void* handle);

    PLANAR_API void Planar_Engine_Core_Log_Logger_log(void* handle,
        const char* text);
    PLANAR_API void Planar_Engine_Core_Log_Logger_warn(void* handle,
        const char* text);
    PLANAR_API void Planar_Engine_Core_Log_Logger_error(void* handle,
        const char* text);
    PLANAR_API void Planar_Engine_Core_Log_Logger_success(void* handle,
        const char* text);
}
