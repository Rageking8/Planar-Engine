#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

#include <string>
#include <vector>
#include <filesystem>

namespace Planar::Engine::Core::Execute
{
    PLANAR_API void run(
        std::filesystem::path working_directory,
        std::filesystem::path program_path,
        std::vector<std::string> arguments);
}
