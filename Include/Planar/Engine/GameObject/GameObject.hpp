#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

#include <string>

namespace Planar::Engine::GameObject
{
    class PLANAR_API GameObject
    {
    public:
        GameObject(const std::string& name = "");
        GameObject(const std::string& name, const std::string& guid);

        std::string get_name() const;
        void set_name(const std::string& new_name);

        std::string get_guid() const;

    private:
        std::string name;
        std::string guid;
    };
}
