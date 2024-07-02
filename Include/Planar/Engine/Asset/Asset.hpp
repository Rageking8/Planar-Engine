#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <array>
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

        template <typename T>
        T get_value(const std::string& key) const;

        template <typename T>
        T get_value(const std::string& key1,
            const std::string& key2) const;

        std::array<float, 2> get_float_2(const std::string& key1,
            const std::string& key2, const std::string& key3) const;

        template <typename T>
        void set_value(const std::string& key1, T value) const;

        template <typename T>
        void set_value(const std::string& key1, const std::string& key2,
            T value) const;

        void set_float_2(const std::string& key1, const std::string& key2,
            const std::string& key3, std::array<float, 2> array) const;

    protected:
        std::unique_ptr<YAML::Node> asset;
    };
}

#include "Planar/Engine/Asset/Asset.tpp"
