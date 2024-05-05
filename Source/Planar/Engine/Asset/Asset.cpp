#include "Planar/Engine/Asset/Asset.hpp"
#include "Planar/Engine/Asset/LoadAssetMacros.hpp"
#include "Planar/Engine/Core/GUID/GUID.hpp"
#include "Planar/Engine/Core/Version.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

#include <iostream>
#include <fstream>

PLANAR_LOAD_STD_STRING_ASSET(Engine, Project)

namespace Planar::Engine::Asset
{
    void iterate_node_recursive(YAML::Node node,
        std::function<void(YAML::Node)> undefined_callback,
        std::function<void(YAML::Node)> null_callback,
        std::function<void(YAML::Node)> scalar_callback,
        std::function<void(YAML::Node)> sequence_callback,
        std::function<void(YAML::Node)> map_callback)
    {
        switch (node.Type())
        {
        case YAML::NodeType::Undefined:
            if (undefined_callback)
            {
                undefined_callback(node);
            }
            break;

        case YAML::NodeType::Null:
            if (null_callback)
            {
                null_callback(node);
            }
            break;

        case YAML::NodeType::Scalar:
            if (scalar_callback)
            {
                scalar_callback(node);
            }
            break;

        case YAML::NodeType::Sequence:
            if (sequence_callback)
            {
                sequence_callback(node);
            }

            for (auto i : node)
            {
                iterate_node_recursive(i, undefined_callback,
                    null_callback, scalar_callback, sequence_callback,
                    map_callback);
            }
            break;

        case YAML::NodeType::Map:
            if (map_callback)
            {
                map_callback(node);
            }

            for (auto i : node)
            {
                iterate_node_recursive(i.second, undefined_callback,
                    null_callback, scalar_callback, sequence_callback,
                    map_callback);
            }
            break;
        }
    }

    void create_project_file(const std::string& project_name,
        const std::string& project_description,
        const std::filesystem::path& output_path)
    {
        create_project_file(project_name, project_description,
            Planar::Asset::Engine::Project, output_path);
    }

    void create_project_file(const std::string& project_name,
        const std::string& project_description,
        const std::string& planar_file,
        const std::filesystem::path& output_path)
    {
        YAML::Node root = YAML::Load(planar_file);

        iterate_node_recursive(root, {}, {},
            [&](YAML::Node node)
            {
                const std::string& value = node.Scalar();

                if (value == "<GUID>")
                {
                    node = Planar::Engine::Core::GUID::generate_guid(
                        Planar::Engine::Core::GUID::Representation::
                        DEFAULT_COMPACT);
                }
                else if (value == "<VERSION>")
                {
                    node = Planar::Engine::Core::VERSION;
                }
                else if (value == "<NAME>")
                {
                    node = project_name;
                }
                else if (value == "<DESCRIPTION>")
                {
                    node = project_description;
                }
            }, {}, {});

        std::ofstream output(output_path / "Project.planar");
        output << root;
    }
}
