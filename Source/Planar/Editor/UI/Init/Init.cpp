#include "Planar/Editor/UI/Init/Init.hpp"
#include "Planar/Engine/Asset/LoadAssetMacros.hpp"
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
}
