#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

#include <string>

namespace Planar::Engine::Core
{
    class PLANAR_API GameObject
    {
    public:
        GameObject(const std::string& name = "");

        std::string get_name() const;
        void set_name(const std::string& new_name);

    private:
        std::string name;
    };
}
