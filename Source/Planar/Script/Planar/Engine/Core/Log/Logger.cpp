#include "Planar/Script/Planar/Engine/Core/Log/Logger.hpp"
#include "Planar/Engine/Core/Log/Logger.hpp"

void* Planar_Engine_Core_Log_Logger_construct()
{
    return new Planar::Engine::Core::Log::Logger;
}

void Planar_Engine_Core_Log_Logger_destruct(void* handle)
{
    delete handle;
}

void Planar_Engine_Core_Log_Logger_log(void* handle,
    const char* text)
{
    static_cast<Planar::Engine::Core::Log::Logger*>(handle)->
        log(text);
}

void Planar_Engine_Core_Log_Logger_warn(void* handle,
    const char* text)
{
    static_cast<Planar::Engine::Core::Log::Logger*>(handle)->
        warn(text);
}

void Planar_Engine_Core_Log_Logger_error(void* handle,
    const char* text)
{
    static_cast<Planar::Engine::Core::Log::Logger*>(handle)->
        error(text);
}

void Planar_Engine_Core_Log_Logger_success(void* handle,
    const char* text)
{
    static_cast<Planar::Engine::Core::Log::Logger*>(handle)->
        success(text);
}
