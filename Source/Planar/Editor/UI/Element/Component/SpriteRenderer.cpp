#include "Planar/Editor/UI/Element/Component/SpriteRenderer.hpp"
#include "Planar/Editor/Core/Editor.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Core/Size/Width.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"
#include "Planar/Engine/Asset/AssetFunction.hpp"
#include "Planar/Engine/Core/Sprite/Sprite.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"
#include "Planar/Engine/Core/FileSystem/SelectDialogFilter.hpp"
#include "Planar/Engine/Core/FileSystem/SelectDialogResult.hpp"
#include "Planar/Engine/Core/Utils/Macros/FunctionalMacros.hpp"

namespace Planar::Editor::UI::Element::Component
{
    SpriteRenderer::SpriteRenderer() :
        sprite("Sprite", "SpriteAsset",
        PLANAR_CAPTURE_THIS_PARAM1(update_sprite_text), {}, 95.f),
        sprite_select_button("Select"), flip_x_checkbox("Flip X"),
        flip_y_checkbox("Flip Y"), tile_factor("Tile Factor",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FILL,
        0.f, 0.f, 20.f }, 120.f, true)
    {

    }

    bool SpriteRenderer::get_modified(bool reset)
    {
        return modified_helper(reset, sprite, active_checkbox,
            flip_x_checkbox, flip_y_checkbox, tile_factor);
    }

    void SpriteRenderer::render_content()
    {
        using namespace Engine::UI;

        render_helper(sprite);
        ImGui::same_line();
        ImGui::Core::Cursor::move_x(12.f);
        sprite_select_button.render();
        if (sprite_select_button.is_clicked())
        {
            Engine::Core::FileSystem::SelectDialogFilter filter;
            filter.add_filter_item("Sprite");

            Engine::Core::FileSystem::SelectDialogResult result =
                Engine::Core::FileSystem::select_file_dialog(filter);

            if (result.check(".planarsprite"))
            {
                sprite.set_asset(Engine::Asset::get_guid(
                    result.get_path()), true);
                sprite.set_text(result.get_filename());
            }
        }

        render_helper(flip_x_checkbox, flip_y_checkbox, tile_factor);
    }

    void SpriteRenderer::set_values_impl(ComponentType* sprite_renderer)
    {
        active_checkbox.set_value(sprite_renderer->get_active());
        sprite.set_asset(sprite_renderer->get_sprite(), false, true);
        flip_x_checkbox.set_value(sprite_renderer->get_flip_x());
        flip_y_checkbox.set_value(sprite_renderer->get_flip_y());
        tile_factor.set_value(sprite_renderer->get_tile_factor().
            get_array());
    }

    void SpriteRenderer::write_values_impl(ComponentType* sprite_renderer)
    {
        sprite_renderer->set_active(active_checkbox.get_value());
        sprite_renderer->set_sprite(sprite.get_asset());
        sprite_renderer->set_flip_x(flip_x_checkbox.get_value());
        sprite_renderer->set_flip_y(flip_y_checkbox.get_value());
        sprite_renderer->set_tile_factor(tile_factor.get_value());
    }

    void SpriteRenderer::update_sprite_text(std::string new_sprite)
    {
        sprite.set_text(editor->get_asset_database().
            get_owning_asset<Engine::Core::Sprite::Sprite>(new_sprite)->
            get_name() + ".planarsprite");
    }
}
