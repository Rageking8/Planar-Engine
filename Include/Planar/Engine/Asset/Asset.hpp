#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>
#include <memory>

PLANAR_FORWARD_DECLARE_CLASS(YAML, Node)

namespace Planar::Engine::Asset
{
    class PLANAR_API Asset
    {
    public:
        Asset();
        virtual ~Asset() = 0;

        void set_node(YAML::Node node);

        void clear();

        bool is_null() const;
        bool is_sequence() const;

        YAML::Node get(const std::string& key1) const;
        YAML::Node get(const std::string& key1,
            const std::string& key2) const;
        YAML::Node get_asset() const;

        std::string get_scalar(const std::string& key) const;
        float get_float(const std::string& key1) const;
        float get_float(const std::string& key1,
            const std::string& key2) const;

    protected:
        std::unique_ptr<YAML::Node> asset;
    };
}
