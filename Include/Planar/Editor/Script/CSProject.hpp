#pragma once

#include <string>
#include <filesystem>

namespace Planar::Editor::Script
{
    class CSProject
    {
    public:
        CSProject();

        void load(const std::string& new_name,
            const std::filesystem::path& new_path);
        void create(const std::string& new_name,
            const std::filesystem::path& new_path);

        std::string get_name() const;
        std::filesystem::path get_path() const;
        std::filesystem::path get_full_path() const;
        std::string get_absolute_path_string() const;

    private:
        std::string name;
        std::filesystem::path path;
    };
}
