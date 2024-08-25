#include "Planar/Editor/Core/Console/CommandLineProcessor.hpp"
#include "Planar/Editor/Core/Console/ProcessResult.hpp"
#include "Planar/Engine/Core/Constants/Version.hpp"

#include "ThirdParty/argparse/argparse.hpp"

#include <iostream>

namespace Planar::Editor::Core::Console
{
    CommandLineProcessor::CommandLineProcessor() : argc{}, argv{},
        argument_parser(std::make_unique<argparse::ArgumentParser>(
        "Planar Editor", generate_version_string(),
        argparse::default_arguments::all, false))
    {

    }

    CommandLineProcessor::~CommandLineProcessor()
    {

    }

    void CommandLineProcessor::set(int new_argc, char* new_argv[])
    {
        argc = new_argc;
        argv = new_argv;
    }

    ProcessResult CommandLineProcessor::process()
    {
        // Either `set` is not called or there
        // are no command line arguments
        if (argc <= 1)
        {
            return {};
        }

        console.create();

        try
        {
            argument_parser->parse_args(argc, argv);
        }
        catch (const std::exception& exception)
        {
            std::cerr << exception.what() << "\n";

            press_enter_to_exit();

            return { -1 };
        }

        std::cout.flush();

        if ((*argument_parser)["-h"] == true ||
            (*argument_parser)["-v"] == true)
        {
            press_enter_to_exit();

            return { 0 };
        }

        return {};
    }

    std::string CommandLineProcessor::generate_version_string() const
    {
        return "Planar Editor\n" + Engine::Core::Constants::VERSION;
    }

    void CommandLineProcessor::press_enter_to_exit() const
    {
        std::cout << "\nPress enter to exit...\n";
        std::string temp;
        std::getline(std::cin, temp);
    }
}
