#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <array>
#include <string>
#include <memory>
#include <filesystem>

PLANAR_FORWARD_DECLARE_CLASS(YAML, Node)

namespace Planar::Engine::Asset
{
    class PLANAR_API Asset
    {
    public:
        Asset();
        virtual ~Asset() = 0;

        virtual void load(const std::string& asset_string);
        virtual void load(const std::filesystem::path& asset_path);

        virtual void write(const std::filesystem::path& write_path) const;

        void set_node(YAML::Node node);

        void clear();

        bool is_null() const;
        bool is_sequence() const;

        YAML::Node get(const std::string& key1) const;
        YAML::Node get(const std::string& key1,
            const std::string& key2) const;
        YAML::Node get_asset() const;

        virtual std::string get_name() const;
        virtual std::string get_guid() const;

        std::string get_string(const std::string& key) const;

        template <typename T>
        T get_value(const std::string& key) const;

        template <typename T>
        T get_value(const std::string& key1,
            const std::string& key2) const;

        template <typename T>
        std::array<T, 2> get_value_2(const std::string& key1,
            const std::string& key2, const std::string& key3) const;

        template <typename T>
        void set_value(const std::string& key1, T value) const;

        template <typename T>
        void set_value(const std::string& key1, const std::string& key2,
            T value) const;

        template <typename T>
        void set_value_2(const std::string& key1, const std::string& key2,
            const std::string& key3, std::array<T, 2> array) const;

    protected:
        std::unique_ptr<YAML::Node> asset;
    };
}

#include "Planar/Engine/Asset/Asset.tpp"
