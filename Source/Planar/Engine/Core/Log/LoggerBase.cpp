#include "Planar/Engine/Core/Log/LoggerBase.hpp"
#include "Planar/Engine/Core/Utils/Terminal/TUI.hpp"

namespace Planar::Engine::Core::Log
{
    LoggerBase::~LoggerBase()
    {

    }

    void LoggerBase::set_name(const std::string& new_name)
    {
        name = new_name;
    }

    std::string LoggerBase::get_timestamp(
        Utils::Time::Format time_format)
    {
        return "[" + Utils::Time::get_time_string(time_format) + "]";
    }

    std::string LoggerBase::get_id(const std::string& type,
        unsigned id, unsigned pad_length, char pad)
    {
        return "[" + type + " ID:" + Utils::Terminal::number_pad_left(id,
            pad_length, pad) + "]";
    }

    std::string LoggerBase::get_name()
    {
        return "[" + name + "]";
    }

    std::string LoggerBase::get_prefix(Utils::Time::Format time_format,
        const std::string& type, unsigned id)
    {
        return get_timestamp(time_format) + get_id(type, id) +
            get_name() + " ";
    }
}
