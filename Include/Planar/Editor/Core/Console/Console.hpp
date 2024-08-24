#pragma once

#include <iosfwd>
#include <fstream>

namespace Planar::Editor::Core::Console
{
    class Console
    {
    public:
        Console();
        ~Console();

        bool create();
        void destroy();

    private:
        std::ofstream out_stream;
        std::ofstream err_stream;
        std::ifstream in_stream;

        std::streambuf* original_out;
        std::streambuf* original_err;
        std::streambuf* original_in;
    };
}
