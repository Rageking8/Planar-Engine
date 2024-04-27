#pragma once

#include "Planar/Engine/Core/ExportMacros.hpp"

#include <string>

namespace Planar::Engine::Core::Utils::Log
{
    class PLANAR_API Logger
    {
    public:
        Logger();

        void log(const std::string& text);
        void warn(const std::string& text);
        void error(const std::string& text);
        void success(const std::string& text);

    private:
        static constexpr unsigned ID_PAD_LENGTH = 4;

        unsigned log_id;
        unsigned warn_id;
        unsigned error_id;
        unsigned success_id;

        std::string get_timestamp() const;
        std::string get_id(const std::string& type, unsigned id);
        std::string get_prefix(const std::string& type, unsigned id);
    };
}
