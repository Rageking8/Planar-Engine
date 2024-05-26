#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

PLANAR_EXPORT_DECLARE_FUNCTION(
    Planar_Engine_Core_Log_TerminalLogger_log,
    void, const char* name, const char* text)
PLANAR_EXPORT_DECLARE_FUNCTION(
    Planar_Engine_Core_Log_TerminalLogger_warn,
    void, const char* name, const char* text)
PLANAR_EXPORT_DECLARE_FUNCTION(
    Planar_Engine_Core_Log_TerminalLogger_error,
    void, const char* name, const char* text)
PLANAR_EXPORT_DECLARE_FUNCTION(
    Planar_Engine_Core_Log_TerminalLogger_success,
    void, const char* name, const char* text)
