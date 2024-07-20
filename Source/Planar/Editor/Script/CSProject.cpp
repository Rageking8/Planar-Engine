#include "Planar/Editor/Script/CSProject.hpp"
#include "Planar/Engine/Asset/LoadAssetMacros.hpp"

PLANAR_LOAD_STD_STRING_ASSET(Editor::Script, BaseProject)

namespace Planar::Editor::Script
{
    CSProject::CSProject()
    {

    }

    void CSProject::load(const std::string& new_name,
        const std::filesystem::path& new_path)
    {
        name = new_name;
        path = new_path;
    }

    void CSProject::create(const std::string& new_name,
        const std::filesystem::path& new_path)
    {
        Engine::Core::FileSystem::create_file(new_path /
            (new_name + ".csproj"),
            Asset::Editor::Script::BaseProject);

        load(new_name, new_path);
    }

    std::string CSProject::get_name() const
    {
        return name;
    }

    std::filesystem::path CSProject::get_path() const
    {
        return path;
    }

    std::filesystem::path CSProject::get_full_path() const
    {
        return path / (name + ".csproj");
    }

    std::string CSProject::get_absolute_path_string() const
    {
        return std::filesystem::absolute(get_full_path()).string();
    }
}
