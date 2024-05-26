#include "Planar/Engine/Core/Log/TerminalLogger.hpp"
#include "Planar/Engine/Core/Utils/Time/Time.hpp"
#include "Planar/Engine/Core/Utils/Terminal/TUI.hpp"

#include <unordered_map>

namespace Planar::Engine::Core::Log
{
    LoggerBase* TerminalLogger::get(const std::string& name)
    {
        static std::unordered_map<std::string, Logger> logger_map;
        logger_map[name].set_name(name);

        return &logger_map[name];
    }

    TerminalLogger::TerminalLogger()
    {

    }

    TerminalLogger::Logger::Logger() : log_id{ 1 }, warn_id{ 1 },
        error_id{ 1 }, success_id{ 1 }
    {

    }

    TerminalLogger::Logger::~Logger()
    {

    }

    void TerminalLogger::Logger::log(const std::string& text)
    {
        Utils::Terminal::color_println(get_prefix(
            Utils::Time::Format::DDMMYYYYHHMMSS, "LOG ", log_id) +
            text, Utils::Terminal::Color::WHITE);

        log_id++;
    }

    void TerminalLogger::Logger::warn(const std::string& text)
    {
        Utils::Terminal::color_println(get_prefix(
            Utils::Time::Format::DDMMYYYYHHMMSS, "WARN", warn_id) +
            text, Utils::Terminal::Color::YELLOW,
            Utils::Terminal::Stream::CLOG);

        warn_id++;
    }

    void TerminalLogger::Logger::error(const std::string& text)
    {
        Utils::Terminal::color_println(get_prefix(
            Utils::Time::Format::DDMMYYYYHHMMSS, "ERR ", error_id) +
            text, Utils::Terminal::Color::RED,
            Utils::Terminal::Stream::CERR);

        error_id++;
    }

    void TerminalLogger::Logger::success(const std::string& text)
    {
        Utils::Terminal::color_println(get_prefix(
            Utils::Time::Format::DDMMYYYYHHMMSS, "SUCC", success_id) +
            text, Utils::Terminal::Color::GREEN);

        success_id++;
    }
}
