#pragma once

#include "Planar/Engine/Core/Utils/Macros/DeclarationMacros.hpp"

#define PLANAR_EDITOR_FORWARD_DECLARE_EXPAND_NS(ns) \
    Planar::Editor::ns                              \

#define PLANAR_EDITOR_FORWARD_DECLARE_CLASS(ns, name)      \
    PLANAR_FORWARD_DECLARE_CLASS(                          \
        PLANAR_EDITOR_FORWARD_DECLARE_EXPAND_NS(ns), name) \
