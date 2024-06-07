#pragma once

#include <string>
#include <filesystem>

namespace Planar::Editor::Script
{
    class CSProject
    {
    public:
        CSProject();

        void create(const std::filesystem::path& path,
            const std::string& name);

        std::string get_name() const;
        std::filesystem::path get_path() const;

    private:
        std::string name;
        std::filesystem::path path;
    };
}
