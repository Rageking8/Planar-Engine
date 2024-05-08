#pragma once

#include "Planar/Engine/Core/ExportMacros.hpp"

extern "C"
{
    PLANAR_DECLARE_CONSTRUCT_DESTRUCT(Planar_Engine_Core_Log_Logger)

    PLANAR_API void Planar_Engine_Core_Log_Logger_log(void* handle,
        const char* text);
    PLANAR_API void Planar_Engine_Core_Log_Logger_warn(void* handle,
        const char* text);
    PLANAR_API void Planar_Engine_Core_Log_Logger_error(void* handle,
        const char* text);
    PLANAR_API void Planar_Engine_Core_Log_Logger_success(void* handle,
        const char* text);
}
