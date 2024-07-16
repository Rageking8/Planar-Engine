#include "Planar/Editor/UI/Element/AssetReference.hpp"
#include "Planar/Engine/UI/ImGui/Core/Size/Width.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"

#include <optional>

namespace Planar::Editor::UI::Element
{
    AssetReference::AssetReference(const std::string& name,
        const std::string& type,
        const std::function<void(std::string)>& update_text_callback,
        const std::function<std::string(std::string)>& map_asset_callback,
        float right_offset, float x_pos) : InputField(name, name,
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FILL,
        0.f, 0.f, right_offset }, x_pos, true), type{ type },
        update_text_callback{ update_text_callback },
        map_asset_callback{ map_asset_callback }
    {

    }

    void AssetReference::render()
    {
        InputField::render();

        std::optional<std::string> drop_result =
            Engine::UI::ImGui::drag_drop_target(type);
        if (drop_result)
        {
            if (map_asset_callback)
            {
                *drop_result = map_asset_callback(*drop_result);
            }

            set_asset(*drop_result);
        }
    }

    std::string AssetReference::get_asset() const
    {
        return asset;
    }

    void AssetReference::set_asset(const std::string& new_asset,
        bool skip_text_update, bool skip_modified)
    {
        asset = new_asset;

        if (!skip_modified)
        {
            set_modified();
        }

        if (skip_text_update)
        {
            return;
        }

        if (asset.empty())
        {
            clear_text();
        }
        else
        {
            update_text_callback(asset);
        }
    }
}
