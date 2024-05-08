#pragma once

#include "Planar/Engine/Core/ExportMacros.hpp"

#include <string>

namespace Planar::Engine::Core::Log
{
    class PLANAR_API LoggerBase
    {
    public:
        virtual ~LoggerBase();

        virtual void log(const std::string& text) = 0;
        virtual void warn(const std::string& text) = 0;
        virtual void error(const std::string& text) = 0;
        virtual void success(const std::string& text) = 0;
    };
}
