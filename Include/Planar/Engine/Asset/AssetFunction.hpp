#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>
#include <vector>
#include <utility>
#include <filesystem>
#include <functional>

PLANAR_FORWARD_DECLARE_CLASS(YAML, Node)

namespace Planar::Engine::Asset
{
    PLANAR_API void iterate_node_recursive(
        YAML::Node node,
        std::function<void(YAML::Node)> undefined_callback = {},
        std::function<void(YAML::Node)> null_callback = {},
        std::function<void(YAML::Node)> scalar_callback = {},
        std::function<void(YAML::Node)> sequence_callback = {},
        std::function<void(YAML::Node)> map_callback = {});

    PLANAR_API std::string preprocess_asset(
        const std::string& asset,
        const std::vector<std::pair<std::string, std::string>>& mapping);
    PLANAR_API std::string preprocess_asset_meta(
        const std::string& asset);
    PLANAR_API std::string preprocess_asset_scalar(
        const std::string& asset,
        const std::vector<std::pair<std::string, std::string>>& mapping);

    PLANAR_API std::string get_value(const std::string& asset,
        const std::string& key);

    PLANAR_API std::string to_string(YAML::Node node);

    PLANAR_API std::string get_guid(
        const std::filesystem::path& asset_path);
}
