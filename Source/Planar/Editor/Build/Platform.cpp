#include "Planar/Editor/Build/Platform.hpp"

namespace Planar::Editor::Build
{
    std::string Platform::get_runtime_identifier() const
    {
        switch (value)
        {
        case WINDOWS_X64:
            return "win-x64";

        default:
            return "";
        }
    }
}
