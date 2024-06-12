#pragma once

#include "Planar/Engine/Asset/Asset.hpp"

#include <string>
#include <filesystem>

namespace Planar::Editor::Asset
{
    class ProjectAsset : public Engine::Asset::Asset
    {
    public:
        ProjectAsset();

        void create(const std::filesystem::path& path,
            const std::string& project_name,
            const std::string& project_description,
            const std::string& main_scene_guid);

    private:
        std::string asset;
    };
}
