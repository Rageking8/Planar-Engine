#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Core/Utils/Terminal/Color.hpp"
#include "Planar/Engine/Core/Utils/Terminal/Stream.hpp"

#include <string>

namespace Planar::Engine::Core::Utils::Terminal
{
    PLANAR_API void* get_std_output_handle();

    PLANAR_API void set_console_color(Color color);
    PLANAR_API void set_console_color(unsigned short color);
    PLANAR_API void reset_console_color();

    PLANAR_API void color_print(const std::string& text, Color color,
        Stream stream = Stream::COUT, bool reset_color = true);
    PLANAR_API void color_println(const std::string& text, Color color,
        Stream stream = Stream::COUT, bool reset_color = true);

    PLANAR_API std::string number_pad_left(unsigned number,
        unsigned length, char pad);
}
