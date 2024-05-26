#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Core/Log/LoggerBase.hpp"

#include <string>

namespace Planar::Engine::Core::Log
{
    class PLANAR_API TerminalLogger
    {
    public:
        static LoggerBase* get(const std::string& name);

    private:
        TerminalLogger();

        class Logger : public LoggerBase
        {
        public:
            Logger();
            virtual ~Logger();

            virtual void log(const std::string& text) override;
            virtual void warn(const std::string& text) override;
            virtual void error(const std::string& text) override;
            virtual void success(const std::string& text) override;

        private:
            unsigned log_id;
            unsigned warn_id;
            unsigned error_id;
            unsigned success_id;
        };
    };
}
