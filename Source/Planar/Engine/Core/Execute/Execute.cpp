#include "Planar/Engine/Core/Execute/Execute.hpp"

#include "ThirdParty/reproc/reproc.hpp"

namespace Planar::Engine::Core::Execute
{
    void run(std::filesystem::path working_directory,
        std::filesystem::path program_path,
        std::vector<std::string> arguments)
    {
        working_directory =
            std::filesystem::absolute(working_directory);
        program_path = std::filesystem::absolute(program_path);
        arguments.insert(arguments.begin(), program_path.string());

        reproc::options options;
        std::string working_directory_string =
            working_directory.string();
        options.working_directory =
            working_directory_string.c_str();

        reproc::process process;
        process.start(arguments, options);

        process.wait(reproc::infinite);
    }
}
