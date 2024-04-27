#include "Planar/Engine/Core/Utils/Terminal/TUI.hpp"

#include "Windows.h"

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
        Stream stream)
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
    }
}
