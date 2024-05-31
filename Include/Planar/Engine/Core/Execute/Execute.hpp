#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

#include <string>
#include <vector>
#include <filesystem>

namespace Planar::Engine::Core::Execute
{
    PLANAR_API int run_program(
        std::filesystem::path working_directory,
        std::filesystem::path program_path,
        std::vector<std::string> arguments);
}
