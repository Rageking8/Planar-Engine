#pragma once

#define PLANAR_DEFINE_ELEMENT_COMPONENT_GET_SET_DRAG_1( \
    component, name)                                    \
    float component::get_##name() const                 \
    {                                                   \
        return name.get_x();                            \
    }                                                   \
                                                        \
    void component::set_##name(float new_##name)        \
    {                                                   \
        name.set_x(new_##name);                         \
    }                                                   \

#define PLANAR_DEFINE_ELEMENT_COMPONENT_GET_SET_DRAG_2( \
    component, type, name)                              \
    type component::get_##name() const                  \
    {                                                   \
        return name.get_value();                        \
    }                                                   \
                                                        \
    void component::set_##name(type new_##name)         \
    {                                                   \
        name.set_value(new_##name.get_array());         \
    }                                                   \
