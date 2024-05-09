#pragma once

#include "Planar/Engine/Core/ExportMacros.hpp"

PLANAR_EXPORT_DECLARE_CONSTRUCT_DESTRUCT(Planar_Engine_Core_Log_Logger)

PLANAR_EXPORT_DECLARE_HANDLE_FUNCTION(Planar_Engine_Core_Log_Logger_log,
    void, const char* text)
PLANAR_EXPORT_DECLARE_HANDLE_FUNCTION(Planar_Engine_Core_Log_Logger_warn,
    void, const char* text)
PLANAR_EXPORT_DECLARE_HANDLE_FUNCTION(Planar_Engine_Core_Log_Logger_error,
    void, const char* text)
PLANAR_EXPORT_DECLARE_HANDLE_FUNCTION(Planar_Engine_Core_Log_Logger_success,
    void, const char* text)
