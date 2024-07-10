#include "Planar/Editor/UI/Element/Component/SpriteRenderer.hpp"
#include "Planar/Editor/Core/Editor.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"
#include "Planar/Engine/Asset/AssetFunction.hpp"
#include "Planar/Engine/Core/Sprite/Sprite.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"
#include "Planar/Engine/Core/FileSystem/SelectDialogFilter.hpp"
#include "Planar/Engine/Core/FileSystem/SelectDialogResult.hpp"

namespace Planar::Editor::UI::Element::Component
{
    SpriteRenderer::SpriteRenderer() : sprite_modified{},
        sprite_select_button("Select")
    {

    }

    bool SpriteRenderer::get_modified(bool reset)
    {
        bool active_modified = active_checkbox.get_modified(reset);
        bool current_sprite_modified = sprite_modified;

        sprite_modified = false;

        return active_modified || current_sprite_modified;
    }

    void SpriteRenderer::render_content()
    {
        using namespace Engine::UI;

        sprite_input.render();
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
    }

    void SpriteRenderer::set_values_impl(ComponentType* sprite_renderer)
    {
        active_checkbox.set_value(sprite_renderer->get_active());
        sprite = sprite_renderer->get_sprite();

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

    void SpriteRenderer::write_values_impl(ComponentType* sprite_renderer)
    {
        sprite_renderer->set_active(active_checkbox.get_value());
        sprite_renderer->set_sprite(sprite);
    }
}
