#include "Planar/Editor/Build/DotnetArguments.hpp"

namespace Planar::Editor::Build
{
    DotnetArguments::DotnetArguments(const Platform& platform,
        const std::filesystem::path& project_path) :
        platform{ platform }, project_path{ project_path }
    {

    }

    void DotnetArguments::add_property(const std::string& property,
        const std::string& value)
    {
        property_map[property] = value;
    }

    Platform DotnetArguments::get_platform() const
    {
        return platform;
    }

    std::filesystem::path DotnetArguments::get_project_path() const
    {
        return project_path;
    }

    std::filesystem::path DotnetArguments::get_artifacts_path() const
    {
        return artifacts_path;
    }

    std::filesystem::path DotnetArguments::get_output_path() const
    {
        return output_path;
    }

    void DotnetArguments::set_platform(const Platform& new_platform)
    {
        platform = new_platform;
    }

    void DotnetArguments::set_project_path(
        const std::filesystem::path& new_project_path)
    {
        project_path = new_project_path;
    }

    void DotnetArguments::set_artifacts_path(
        const std::filesystem::path& new_artifacts_path)
    {
        artifacts_path = new_artifacts_path;
    }

    void DotnetArguments::set_output_path(
        const std::filesystem::path& new_output_path)
    {
        output_path = new_output_path;
    }

    std::vector<std::string> DotnetArguments::generate_publish_vector()
        const
    {
        return generate_vector("publish");
    }

    std::vector<std::string> DotnetArguments::generate_vector(
        const std::string& command) const
    {
        std::vector<std::string> result;
        result.reserve(12);

        result.insert(result.end(),
            { command, get_path_string(project_path),
            "-r", platform.get_runtime_identifier() });

        for (const auto& i : property_map)
        {
            result.push_back("-p:" + i.first + "=" + i.second);
        }

        if (!artifacts_path.empty())
        {
            result.insert(result.end(), { "--artifacts-path",
                get_path_string(artifacts_path) });
        }

        if (!output_path.empty())
        {
            result.insert(result.end(), { "-o",
                get_path_string(output_path) });
        }

        return result;
    }

    std::string DotnetArguments::get_path_string(
        const std::filesystem::path& path) const
    {
        return std::filesystem::absolute(path).string();
    }
}
