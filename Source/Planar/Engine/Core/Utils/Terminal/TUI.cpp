#include "Planar/Engine/Core/Utils/Terminal/TUI.hpp"

#include <Windows.h>

#include <iostream>

namespace Planar::Engine::Core::Utils::Terminal
{
    HANDLE get_std_output_handle()
    {
        static HANDLE std_output_handle =
            GetStdHandle(STD_OUTPUT_HANDLE);

        return std_output_handle;
    }

    void set_console_color(Color color)
    {
        set_console_color(static_cast<unsigned short>(color));
    }

    void set_console_color(unsigned short color)
    {
        SetConsoleTextAttribute(get_std_output_handle(), color);
    }

    void reset_console_color()
    {
        set_console_color(Color::DEFAULT);
    }

    void color_print(const std::string& text, Color color,
        Stream stream, bool reset_color)
    {
        set_console_color(color);

        switch (stream)
        {
        case Stream::COUT:
            std::cout << text;
            break;

        case Stream::CERR:
            std::cerr << text;
            break;

        case Stream::CLOG:
            std::clog << text;
            break;
        }

        if (reset_color)
        {
            reset_console_color();
        }
    }

    void color_println(const std::string& text, Color color,
        Stream stream, bool reset_color)
    {
        color_print(text + "\n", color, stream, reset_color);
    }

    std::string number_pad_left(unsigned number, unsigned length,
        char pad)
    {
        std::string number_string = std::to_string(number);

        if (number_string.length() >= length)
        {
            return number_string;
        }

        return std::string(length - number_string.length(), pad) +
            number_string;
    }
}
