#include "Planar/Editor/UI/Element/Component/SpriteRenderer.hpp"
#include "Planar/Editor/Core/Editor.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"
#include "Planar/Engine/Asset/AssetFunction.hpp"
#include "Planar/Engine/Core/Sprite/Sprite.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"
#include "Planar/Engine/Core/FileSystem/SelectDialogFilter.hpp"
#include "Planar/Engine/Core/FileSystem/SelectDialogResult.hpp"

#include <optional>

namespace Planar::Editor::UI::Element::Component
{
    SpriteRenderer::SpriteRenderer() : sprite_modified{},
        sprite_input("Sprite", true), sprite_select_button("Select"),
        flip_x_checkbox("Flip X"), flip_y_checkbox("Flip Y")
    {

    }

    bool SpriteRenderer::get_modified(bool reset)
    {
        bool current_sprite_modified = sprite_modified;
        sprite_modified = false;

        return modified_helper(reset, active_checkbox, flip_x_checkbox,
            flip_y_checkbox) || current_sprite_modified;
    }

    void SpriteRenderer::render_content()
    {
        using namespace Engine::UI;

        render_helper(sprite_input);
        std::optional<std::string> drop_result =
            ImGui::drag_drop_target("SpriteAsset");
        if (drop_result)
        {
            update_sprite(*drop_result);
            sprite_modified = true;
        }

        ImGui::same_line();
        ImGui::Core::Cursor::move_x(24.f);
        sprite_select_button.render();
        if (sprite_select_button.is_clicked())
        {
            Engine::Core::FileSystem::SelectDialogFilter filter;
            filter.add_filter_item("Sprite");

            Engine::Core::FileSystem::SelectDialogResult result =
                Engine::Core::FileSystem::select_file_dialog(filter);

            if (result.check(".planarsprite"))
            {
                sprite = Engine::Asset::get_guid(result.get_path());
                sprite_input.set_text(result.get_filename());
                sprite_modified = true;
            }
        }

        render_helper(flip_x_checkbox, flip_y_checkbox);
    }

    void SpriteRenderer::set_values_impl(ComponentType* sprite_renderer)
    {
        active_checkbox.set_value(sprite_renderer->get_active());
        update_sprite(sprite_renderer->get_sprite());
        flip_x_checkbox.set_value(sprite_renderer->get_flip_x());
        flip_y_checkbox.set_value(sprite_renderer->get_flip_y());
    }

    void SpriteRenderer::write_values_impl(ComponentType* sprite_renderer)
    {
        sprite_renderer->set_active(active_checkbox.get_value());
        sprite_renderer->set_sprite(sprite);
        sprite_renderer->set_flip_x(flip_x_checkbox.get_value());
        sprite_renderer->set_flip_y(flip_y_checkbox.get_value());
    }

    void SpriteRenderer::update_sprite(const std::string& new_sprite)
    {
        sprite = new_sprite;

        if (sprite.empty())
        {
            sprite_input.clear_text();
        }
        else
        {
            sprite_input.set_text(editor->get_asset_database().
                get_owning_asset<Engine::Core::Sprite::Sprite>(sprite)->
                get_name() + ".planarsprite");
        }
    }
}
