#include "Planar/Editor/UI/Window/AssetImportWindow.hpp"
#include "Planar/Editor/Core/Editor.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Core/Size/Width.hpp"
#include "Planar/Engine/UI/ImGui/Core/Cursor/Cursor.hpp"
#include "Planar/Engine/Core/Log/TerminalLogger.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"
#include "Planar/Engine/Core/FileSystem/SelectDialogResult.hpp"
#include "Planar/Engine/Core/Sprite/Sprite.hpp"
#include "Planar/Engine/Asset/AssetDatabase.hpp"

#include <memory>
#include <filesystem>

namespace Planar::Editor::UI::Window
{
    AssetImportWindow::AssetImportWindow(Editor::Core::Editor* editor) :
        EditorWindow("Asset Import", editor, false),
        asset_path_input("Asset path"), browse_button("Browse"),
        import_type_dropdown("Import type:",
        { Engine::UI::ImGui::Core::Size::Width::WidthMode::FIXED, 200.f }),
        import_button("Import"), pending_browse{}, pending_import{}
    {
        set_size({ { 1440.f, 810.f } });
        set_min_size({ { 500.f, 400.f } });
        set_padding({ { 24.f, 0.f } });
        set_flags(Engine::UI::ImGui::Window::WindowFlags::
            VIEWPORT_CENTER);
    }

    void AssetImportWindow::update()
    {
        if (pending_browse)
        {
            browse();
        }

        update_import_options();

        if (pending_import)
        {
            import();
        }
    }

    void AssetImportWindow::render_window()
    {
        using namespace Planar::Engine::UI;

        std::unique_ptr<Window::Scope> result = render();

        if (!result)
        {
            return;
        }

        ImGui::Core::Cursor::set_y(60.f);

        asset_path_input.render();
        ImGui::same_line();
        browse_button.render();
        if (browse_button.is_clicked())
        {
            pending_browse = true;
        }

        const float separator_extra_height = 12.f;

        ImGui::separator(separator_extra_height);

        import_type_dropdown.render();

        ImGui::separator(separator_extra_height);

        ImGui::Core::Cursor::set_y_bottom_window(
            -separator_extra_height);
        import_button.render();
        if (import_button.is_clicked())
        {
            pending_import = true;
        }
    }

    void AssetImportWindow::browse()
    {
        pending_browse = false;

        Engine::Core::FileSystem::SelectDialogResult result =
            Engine::Core::FileSystem::select_file_dialog();

        if (!result)
        {
            if (result.has_error())
            {
                Engine::Core::Log::TerminalLogger::get("Editor")->
                    error(result.get_error());
            }

            return;
        }

        asset_path_input.set_text(result.get_path().string());
    }

    void AssetImportWindow::import()
    {
        pending_import = false;

        Engine::Asset::AssetDatabase* asset_database =
            editor->get_asset_database();
        const std::filesystem::path asset_path = asset_path_input.
            get_text();

        if (asset_extension == ".png")
        {
            asset_database->create_owning_asset<
                Engine::Core::Sprite::Sprite>(asset_path);

            set_active(false);
        }
    }

    void AssetImportWindow::update_import_options()
    {
        std::filesystem::path asset_path(asset_path_input.get_text());
        std::string new_asset_extension = asset_path.extension().
            string();

        if (new_asset_extension == asset_extension)
        {
            return;
        }

        if (new_asset_extension == ".png")
        {
            import_type_dropdown.set_options({ "Sprite" });
        }
        else
        {
            import_type_dropdown.set_options({});
        }

        asset_extension = new_asset_extension;
    }
}
