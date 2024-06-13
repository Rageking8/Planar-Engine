#pragma once

#include "Planar/Editor/Build/Platform.hpp"

#include <string>
#include <vector>
#include <filesystem>
#include <unordered_map>

namespace Planar::Editor::Build
{
    class DotnetArguments
    {
    public:
        DotnetArguments(const Platform& platform,
            const std::filesystem::path& project_path);

        void add_property(const std::string& property,
            const std::string& value);

        Platform get_platform() const;
        std::filesystem::path get_project_path() const;
        std::filesystem::path get_artifacts_path() const;
        std::filesystem::path get_output_path() const;

        void set_platform(const Platform& new_platform);
        void set_project_path(
            const std::filesystem::path& new_project_path);
        void set_artifacts_path(
            const std::filesystem::path& new_artifacts_path);
        void set_output_path(
            const std::filesystem::path& new_output_path);

        std::vector<std::string> generate_publish_vector() const;

    private:
        Platform platform;
        std::filesystem::path project_path;
        std::filesystem::path artifacts_path;
        std::filesystem::path output_path;
        std::unordered_map<std::string, std::string> property_map;

        std::vector<std::string> generate_vector(
            const std::string& command) const;

        std::string get_path_string(
            const std::filesystem::path& path) const;
    };
}
