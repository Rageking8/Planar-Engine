#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

#include <string>
#include <vector>
#include <utility>
#include <functional>
#include <filesystem>

namespace YAML
{
    class Node;
}

namespace Planar::Engine::Asset
{
    PLANAR_API void iterate_node_recursive(
        YAML::Node node,
        std::function<void(YAML::Node)> undefined_callback = {},
        std::function<void(YAML::Node)> null_callback = {},
        std::function<void(YAML::Node)> scalar_callback = {},
        std::function<void(YAML::Node)> sequence_callback = {},
        std::function<void(YAML::Node)> map_callback = {});

    PLANAR_API std::string preprocess_asset_meta(const std::string& asset);
    PLANAR_API std::string preprocess_asset_scalar(const std::string& asset,
        const std::vector<std::pair<std::string, std::string>>& mapping);

    PLANAR_API void create_project_file(
        const std::string& project_name,
        const std::string& project_description,
        const std::filesystem::path& output_path);
    PLANAR_API void create_project_file(
        const std::string& project_name,
        const std::string& project_description,
        const std::string& planar_file,
        const std::filesystem::path& output_path);
}
