#pragma once

#include "Planar/Engine/Core/Utils/Macros/MacroUtils.hpp"

#define PLANAR_DEFINE_GET_SET_RAW(type, get_set_type, name, \
    get_content, set_content)                               \
    get_set_type type::get_##name() const                   \
    {                                                       \
        get_content                                         \
    }                                                       \
                                                            \
    void type::set_##name(get_set_type new_##name)          \
    {                                                       \
        set_content                                         \
    }                                                       \

#define PLANAR_DEFINE_GET_SET(type, get_set_type, name, \
    get_content, set_content)                           \
    PLANAR_DEFINE_GET_SET_RAW(type, get_set_type, name, \
        get_content                                     \
        return name;,                                   \
                                                        \
        name = PLANAR_CONCAT(new_, name);               \
        set_content                                     \
    )                                                   \
