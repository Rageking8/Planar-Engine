#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Core/Utils/Time/Time.hpp"

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

        void set_name(const std::string& new_name);

    protected:
        std::string name;

        std::string get_timestamp(Utils::Time::Format time_format);
        std::string get_id(const std::string& type,
            unsigned id, unsigned pad_length = 4, char pad = ' ');
        std::string get_name();
        std::string get_prefix(Utils::Time::Format time_format,
            const std::string& type, unsigned id);
    };
}
