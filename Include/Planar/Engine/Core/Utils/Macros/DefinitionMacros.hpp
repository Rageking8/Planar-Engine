#pragma once

#define PLANAR_DEFINE_GET_SET(type, get_set_type, name, \
    get_content, set_content)                           \
    get_set_type type::get_##name() const               \
    {                                                   \
        get_content                                     \
        return name;                                    \
    }                                                   \
                                                        \
    void type::set_##name(get_set_type new_##name)      \
    {                                                   \
        name = new_##name;                              \
        set_content                                     \
    }                                                   \
