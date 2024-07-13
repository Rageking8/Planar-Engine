#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Asset/Asset.hpp"
#include "Planar/Engine/Math/Size2D.hpp"
#include "Planar/Engine/Graphics/SupportedGraphicsAPI.hpp"
#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#include <string>
#include <filesystem>

namespace Planar::Engine::Core
{
    class PLANAR_API ApplicationAsset : public Asset::Asset
    {
    public:
        ApplicationAsset();

        virtual void load(const std::string& asset_string) override;

        virtual void write(const std::filesystem::path& write_path)
            const override;

        const std::string& get_window_name() const;
        void set_window_name(std::string new_window_name);

        PLANAR_DECLARE_GET_SET(Math::Size2Di, window_size)
        PLANAR_DECLARE_GET_SET(bool, maximize_window)
        PLANAR_DECLARE_GET_SET(Graphics::SupportedGraphicsAPI,
            graphics_api)

    private:
        std::string window_name;
        Math::Size2Di window_size;
        bool maximize_window;
        Graphics::SupportedGraphicsAPI graphics_api;
    };
}
