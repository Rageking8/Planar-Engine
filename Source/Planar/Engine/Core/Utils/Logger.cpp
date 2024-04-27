#include "Planar/Engine/Core/Utils/Logger.hpp"
#include "Planar/Engine/Core/Utils/Time/Time.hpp"
#include "Planar/Engine/Core/Utils/Terminal/TUI.hpp"

namespace Planar::Engine::Core::Utils
{
    Logger::Logger() : log_id{ 1 }, warn_id{ 1 },
        error_id{ 1 }, success_id{ 1 }
    {

    }

    void Logger::log(const std::string& text)
    {
        Terminal::color_println(get_prefix("LOG ", log_id) + text,
            Terminal::Color::WHITE);

        log_id++;
    }

    void Logger::warn(const std::string& text)
    {
        Terminal::color_println(get_prefix("WARN", warn_id) + text,
            Terminal::Color::YELLOW, Terminal::Stream::CLOG);

        warn_id++;
    }

    void Logger::error(const std::string& text)
    {
        Terminal::color_println(get_prefix("ERR ", error_id) + text,
            Terminal::Color::RED, Terminal::Stream::CERR);

        error_id++;
    }

    void Logger::success(const std::string& text)
    {
        Terminal::color_println(get_prefix("SUCC", success_id) + text,
            Terminal::Color::GREEN);

        success_id++;
    }

    std::string Logger::get_timestamp() const
    {
        return "[" + Time::get_time_string(
            Time::Format::DDMMYYYYHHMMSS) + "]";
    }

    std::string Logger::get_id(const std::string& type, unsigned id)
    {
        return "[" + type + ":" +
            Terminal::number_pad_left(id, ID_PAD_LENGTH, ' ') + "]";
    }

    std::string Logger::get_prefix(const std::string& type, unsigned id)
    {
        return get_timestamp() + get_id(type, id) + " ";
    }
}
