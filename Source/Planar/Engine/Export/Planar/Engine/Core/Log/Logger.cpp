#include "Planar/Engine/Export/Planar/Engine/Core/Log/Logger.hpp"
#include "Planar/Engine/Core/Log/Logger.hpp"

PLANAR_EXPORT_DEFINE_CONSTRUCT_DESTRUCT(Planar_Engine_Core_Log_Logger,
    Planar::Engine::Core::Log::Logger)

PLANAR_EXPORT_DEFINE_HANDLE_FUNCTION(Planar_Engine_Core_Log_Logger,
    log, const char* text, text, Planar::Engine::Core::Log::Logger)
PLANAR_EXPORT_DEFINE_HANDLE_FUNCTION(Planar_Engine_Core_Log_Logger,
    warn, const char* text, text, Planar::Engine::Core::Log::Logger)
PLANAR_EXPORT_DEFINE_HANDLE_FUNCTION(Planar_Engine_Core_Log_Logger,
    error, const char* text, text, Planar::Engine::Core::Log::Logger)
PLANAR_EXPORT_DEFINE_HANDLE_FUNCTION(Planar_Engine_Core_Log_Logger,
    success, const char* text, text, Planar::Engine::Core::Log::Logger)
