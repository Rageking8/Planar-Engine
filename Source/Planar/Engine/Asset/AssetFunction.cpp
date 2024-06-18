#include "Planar/Engine/Asset/AssetFunction.hpp"
#include "Planar/Engine/Asset/LoadAssetMacros.hpp"

#include "ThirdParty/yaml-cpp/yaml.h"

PLANAR_LOAD_STD_STRING_ASSET(Engine, BasicPrelude)

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

    std::string preprocess_asset(const std::string& asset,
        const std::vector<std::pair<std::string, std::string>>& mapping)
    {
        return preprocess_asset_scalar(
            preprocess_asset_meta(asset), mapping);
    }

    std::string preprocess_asset_meta(const std::string& asset)
    {
        YAML::Node root = YAML::Load(asset);
        YAML::Node result = YAML::Clone(root);

        if (root.Type() != YAML::NodeType::Map)
        {
            return asset;
        }

        std::string prepend;

        for (auto i : root)
        {
            if (i.first.Scalar() == "<PRELUDE>")
            {
                if (i.second.Scalar() == "BasicPrelude")
                {
                    prepend += Planar::Asset::Engine::BasicPrelude;
                    result.remove(i.first.Scalar());
                }
            }
        }

        return prepend + YAML::Dump(result);
    }

    std::string preprocess_asset_scalar(const std::string& asset,
        const std::vector<std::pair<std::string, std::string>>& mapping)
    {
        YAML::Node root = YAML::Load(asset);

        iterate_node_recursive(root, {}, {},
            [&](YAML::Node node)
            {
                const std::string& value = node.Scalar();

                for (const auto& i : mapping)
                {
                    if (value == i.first)
                    {
                        node = i.second;
                    }
                }
            }, {}, {});

        return YAML::Dump(root);
    }

    std::string get_value(const std::string& asset,
        const std::string& key)
    {
        YAML::Node root = YAML::Load(asset);

        return root[key].as<std::string>();
    }

    std::string to_string(YAML::Node node)
    {
        YAML::Emitter emitter;
        emitter.SetSeqFormat(YAML::EMITTER_MANIP::Block);
        emitter << node;

        return emitter.c_str();
    }
}
