#include "Planar/Engine/Script/ScriptDatabase.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"

namespace Planar::Engine::Script
{
    ScriptDatabase::ScriptDatabase()
    {

    }

    void ScriptDatabase::load_scripts_recursive(
        const std::filesystem::path& root)
    {
        Core::FileSystem::iterate_files_recursive(root,
            [&](const std::filesystem::path& path)
            {
                if (path.extension() == ".cs")
                {
                    script_names.insert(path.stem().string());
                }
            }, { "Build", "Cache", "Engine" });
    }

    bool ScriptDatabase::exists(const std::string& name) const
    {
        return script_names.contains(name);
    }

    bool ScriptDatabase::create(std::filesystem::path path,
        const std::string& name, std::string asset)
    {
        if (name.empty() || exists(name))
        {
            return false;
        }

        path /= name + ".cs";

        Core::FileSystem::create_file(path,
            asset.replace(asset.find("<NAME>"), 6, name));

        script_names.insert(name);

        return true;
    }

    const std::set<std::string>& ScriptDatabase::get_script_names()
        const
    {
        return script_names;
    }
}
