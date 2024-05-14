#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"

#define PLANAR_DECLARE_IMGUI_WRAPPER(name) \
    class PLANAR_API name                  \
    {                                      \
    public:                                \
        name();                            \
        ~name();                           \
    };                                     \

#define PLANAR_DEFINE_IMGUI_WRAPPER(name, start, end) \
    name::name()                                      \
    {                                                 \
        ::ImGui::start();                             \
    }                                                 \
                                                      \
    name::~name()                                     \
    {                                                 \
        ::ImGui::end();                               \
    }                                                 \
