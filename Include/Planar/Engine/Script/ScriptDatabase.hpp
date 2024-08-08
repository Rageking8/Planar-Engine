#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

#include <set>
#include <string>
#include <filesystem>

namespace Planar::Engine::Script
{
    class PLANAR_API ScriptDatabase
    {
    public:
        ScriptDatabase();

        void load_scripts_recursive(const std::filesystem::path& root);

        bool exists(const std::string& name) const;

        bool create(std::filesystem::path path,
            const std::string& name, std::string asset);

        const std::set<std::string>& get_script_names() const;

    private:
        std::set<std::string> script_names;
    };
}
