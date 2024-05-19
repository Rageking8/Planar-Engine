#pragma once

#include "Planar/Engine/Asset/LoadAssetMacros.hpp"

#define PLANAR_LOAD_EDITOR_ICON(name)                          \
    PLANAR_LOAD_UNSIGNED_CHAR_ARRAY_ASSET(Editor::Icons, name) \

#define PLANAR_LOAD_EDITOR_ICON_TEXTURE(texture, name) \
    texture.load(Planar::Asset::Editor::Icons::name,   \
        Planar::Asset::Editor::Icons::name##_length);  \
