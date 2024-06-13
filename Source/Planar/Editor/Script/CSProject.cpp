#include "Planar/Editor/Script/CSProject.hpp"
#include "Planar/Engine/Asset/LoadAssetMacros.hpp"

PLANAR_LOAD_STD_STRING_ASSET(Editor::Script, BaseProject)

namespace Planar::Editor::Script
{
    CSProject::CSProject()
    {

    }

    void CSProject::create(const std::filesystem::path& path,
        const std::string& name)
    {
        Engine::Core::FileSystem::create_file(path /
            (name + ".csproj"),
            Asset::Editor::Script::BaseProject);

        this->path = path;
        this->name = name;
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
