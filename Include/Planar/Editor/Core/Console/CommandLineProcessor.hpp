#pragma once

#include "Planar/Editor/Core/Console/Console.hpp"
#include "Planar/Editor/Core/Utils/Macros/DeclarationMacros.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>
#include <memory>

PLANAR_FORWARD_DECLARE_CLASS(argparse, ArgumentParser)
PLANAR_EDITOR_FORWARD_DECLARE_CLASS(Core::Console, ProcessResult)

namespace Planar::Editor::Core::Console
{
    class CommandLineProcessor
    {
    public:
        CommandLineProcessor();
        ~CommandLineProcessor();

        void set(int new_argc, char* new_argv[]);
        ProcessResult process();

    private:
        Console console;
        int argc;
        char** argv;

        std::unique_ptr<argparse::ArgumentParser> argument_parser;

        std::string generate_version_string() const;
        void press_enter_to_exit() const;
    };
}
