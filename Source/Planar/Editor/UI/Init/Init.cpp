#include "Planar/Editor/UI/Init/Init.hpp"
#include "Planar/Engine/Asset/LoadAssetMacros.hpp"
#include "Planar/Engine/UI/ImGui/ImGui.hpp"
#include "Planar/Engine/UI/ImGui/Font/Font.hpp"

PLANAR_LOAD_UNSIGNED_CHAR_ARRAY_ASSET(Editor::Fonts, Roboto)

namespace Planar::Editor::UI::Init
{
    void load_default_font()
    {
        Engine::UI::ImGui::Font::load_font(
            Asset::Editor::Fonts::Roboto,
            Asset::Editor::Fonts::Roboto_length, 18.f);
    }

    void set_scale()
    {
        Engine::UI::ImGui::scale_ui(3);
        Engine::UI::ImGui::set_scrollbar_size(15.f);
    }
}
