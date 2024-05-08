#pragma once

#include "Planar/Engine/Core/ExportMacros.hpp"
#include "Planar/Engine/Core/Log/LoggerBase.hpp"

#include <string>

namespace Planar::Engine::Core::Log
{
    class PLANAR_API Logger : public LoggerBase
    {
    public:
        Logger();

        virtual void log(const std::string& text) override;
        virtual void warn(const std::string& text) override;
        virtual void error(const std::string& text) override;
        virtual void success(const std::string& text) override;

    private:
        static constexpr unsigned ID_PAD_LENGTH = 4;

        unsigned log_id;
        unsigned warn_id;
        unsigned error_id;
        unsigned success_id;

        std::string get_timestamp() const;
        std::string get_id(const std::string& type, unsigned id);
        std::string get_prefix(const std::string& type, unsigned id);
    };
}
