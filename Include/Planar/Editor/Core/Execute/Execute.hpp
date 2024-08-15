#pragma once

#include <string>
#include <vector>
#include <filesystem>

namespace Planar::Editor::Core::Execute
{
    int run_program(std::filesystem::path program_path,
        std::vector<std::string> arguments,
        std::filesystem::path working_directory = ".");
}
