#include "Planar/Engine/Core/Log/Logger.hpp"
#include "Planar/Engine/Core/Utils/Time/Time.hpp"
#include "Planar/Engine/Core/Utils/Terminal/TUI.hpp"

namespace Planar::Engine::Core::Log
{
    Logger::Logger() : log_id{ 1 }, warn_id{ 1 },
        error_id{ 1 }, success_id{ 1 }
    {

    }

    Logger::~Logger()
    {

    }

    void Logger::log(const std::string& text)
    {
        Planar::Engine::Core::Utils::Terminal::color_println(
            get_prefix("LOG ", log_id) + text,
            Planar::Engine::Core::Utils::Terminal::Color::WHITE);

        log_id++;
    }

    void Logger::warn(const std::string& text)
    {
        Planar::Engine::Core::Utils::Terminal::color_println(
            get_prefix("WARN", warn_id) + text,
            Planar::Engine::Core::Utils::Terminal::Color::YELLOW,
            Planar::Engine::Core::Utils::Terminal::Stream::CLOG);

        warn_id++;
    }

    void Logger::error(const std::string& text)
    {
        Planar::Engine::Core::Utils::Terminal::color_println(
            get_prefix("ERR ", error_id) + text,
            Planar::Engine::Core::Utils::Terminal::Color::RED,
            Planar::Engine::Core::Utils::Terminal::Stream::CERR);

        error_id++;
    }

    void Logger::success(const std::string& text)
    {
        Planar::Engine::Core::Utils::Terminal::color_println(
            get_prefix("SUCC", success_id) + text,
            Planar::Engine::Core::Utils::Terminal::Color::GREEN);

        success_id++;
    }

    std::string Logger::get_timestamp() const
    {
        return "[" + Planar::Engine::Core::Utils::Time::get_time_string(
            Planar::Engine::Core::Utils::Time::Format::DDMMYYYYHHMMSS) +
            "]";
    }

    std::string Logger::get_id(const std::string& type, unsigned id)
    {
        return "[" + type + " ID:" +
            Planar::Engine::Core::Utils::Terminal::number_pad_left(id,
            ID_PAD_LENGTH, ' ') + "]";
    }

    std::string Logger::get_prefix(const std::string& type, unsigned id)
    {
        return get_timestamp() + get_id(type, id) + " ";
    }
}
