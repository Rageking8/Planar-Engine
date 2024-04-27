#include "Planar/Engine/Core/Utils/Time/Time.hpp"

#include <ctime>
#include <iomanip>
#include <sstream>

namespace Planar::Engine::Core::Utils::Time
{
    std::string get_time_string(Format format)
    {
        const std::time_t time = std::time(nullptr);
        const tm* local_time = std::localtime(&time);
        std::ostringstream output;

        switch (format)
        {
        case Format::HHMMSS:
            output << std::put_time(local_time, "%H:%M:%S");
            break;

        case Format::DDMMYYYY:
            output << std::put_time(local_time, "%d/%m/%Y");
            break;

        case Format::DDMMYYYYHHMMSS:
            output << std::put_time(local_time, "%d/%m/%Y %H:%M:%S");
            break;
        }

        return output.str();
    }
}
