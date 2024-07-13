#pragma once

#define PLANAR_DEFINE_COMPONENT_ASSET_GET_SET_VALUE(   \
    component, type, name, key)                        \
    type component##Asset::get_##name() const          \
    {                                                  \
        return get_value<type>(#key);                  \
    }                                                  \
                                                       \
    void component##Asset::set_##name(type new_##name) \
    {                                                  \
        set_value(#key, new_##name);                   \
    }                                                  \

#define PLANAR_DEFINE_COMPONENT_ASSET_GET_SET_FLOAT_2(            \
    component, type, name, key1, key2, key3)                      \
    type component##Asset::get_##name() const                     \
    {                                                             \
        return get_value_2<float>(#key1, #key2, #key3);           \
    }                                                             \
                                                                  \
    void component##Asset::set_##name(type new_##name)            \
    {                                                             \
        set_value_2(#key1, #key2, #key3, new_##name.get_array()); \
    }                                                             \
