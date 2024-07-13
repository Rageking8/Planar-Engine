#include "Planar/Engine/Core/ApplicationAsset.hpp"
#include "Planar/Engine/Core/Utils/Macros/DefinitionMacros.hpp"

namespace Planar::Engine::Core
{
    ApplicationAsset::ApplicationAsset() : maximize_window{},
        graphics_api{ Graphics::SupportedGraphicsAPI::OPENGL_4_6 }
    {

    }

    void ApplicationAsset::load(const std::string& asset_string)
    {
        Asset::load(asset_string);

        window_name = get_value<std::string>("WindowName");
        window_size = get_value_2<int>("WindowSize", "Width", "Height");
        maximize_window = get_value<bool>("MaximizeWindow");
        graphics_api = static_cast<Graphics::SupportedGraphicsAPIBacking>(
            get_value<int>("GraphicsAPI"));
    }

    void ApplicationAsset::write(const std::filesystem::path& write_path)
        const
    {
        set_value("WindowName", window_name);
        set_value_2("WindowSize", "Width", "Height",
            window_size.get_array());
        set_value("MaximizeWindow", maximize_window);
        set_value("GraphicsAPI", graphics_api.get_int());

        Asset::write(write_path);
    }

    const std::string& ApplicationAsset::get_window_name() const
    {
        return window_name;
    }

    void ApplicationAsset::set_window_name(std::string new_window_name)
    {
        window_name = new_window_name;
    }

    PLANAR_DEFINE_GET_SET(ApplicationAsset, Math::Size2Di, window_size)
    PLANAR_DEFINE_GET_SET(ApplicationAsset, bool, maximize_window)
    PLANAR_DEFINE_GET_SET(ApplicationAsset,
        Graphics::SupportedGraphicsAPI, graphics_api)
}
