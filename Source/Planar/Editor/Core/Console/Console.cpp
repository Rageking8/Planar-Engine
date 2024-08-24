#include "Planar/Editor/Core/Console/Console.hpp"
#include "Planar/Editor/Core/Console/Handle.hpp"

#include <Windows.h>

#include <iostream>

namespace Planar::Editor::Core::Console
{
    Console::Console() : original_out{},
        original_err{}, original_in{}
    {

    }

    Console::~Console()
    {
        destroy();
    }

    bool Console::create()
    {
        if (!AllocConsole())
        {
            return false;
        }

        out_stream.open(CONOUT, std::ios::out);
        err_stream.open(CONOUT, std::ios::out);
        in_stream.open(CONIN, std::ios::in);

        original_out = std::cout.rdbuf(out_stream.rdbuf());
        original_err = std::cerr.rdbuf(err_stream.rdbuf());
        original_in = std::cin.rdbuf(in_stream.rdbuf());

        return true;
    }

    void Console::destroy()
    {
        if (!original_out)
        {
            return;
        }

        out_stream.close();
        err_stream.close();
        in_stream.close();

        std::cout.rdbuf(original_out);
        std::cerr.rdbuf(original_err);
        std::cin.rdbuf(original_in);

        FreeConsole();

        original_out = nullptr;
        original_err = nullptr;
        original_in = nullptr;
    }
}
