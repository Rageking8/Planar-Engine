#pragma once

#include "Planar/Engine/UI/ImGui/Element/InputField.hpp"

#include <string>
#include <functional>

namespace Planar::Editor::UI::Element
{
    class AssetReference :
        public Engine::UI::ImGui::Element::InputField
    {
    public:
        AssetReference(const std::string& name, const std::string& type,
            const std::function<void(std::string)>& update_text_callback,
            const std::function<std::string(std::string)>&
            map_asset_callback = {}, float right_offset = 20.f,
            float x_pos = 100.f);

        virtual void render() override;

        std::string get_asset() const;
        void set_asset(const std::string& new_asset,
            bool skip_text_update = false, bool skip_modified = false);

    private:
        std::string type;
        std::string asset;
        std::function<void(std::string)> update_text_callback;
        std::function<std::string(std::string)> map_asset_callback;
    };
}
