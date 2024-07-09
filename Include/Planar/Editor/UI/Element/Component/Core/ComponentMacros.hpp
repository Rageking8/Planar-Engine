#pragma once

#include "Planar/Engine/Core/Utils/Macros/DefinitionMacros.hpp"

#define PLANAR_DEFINE_ELEMENT_COMPONENT_GET_SET_DRAG_1( \
    component, name)                                    \
    PLANAR_DEFINE_GET_SET_RAW(component, float, name,   \
        return name.get_x();,                           \
                                                        \
        name.set_x(new_##name);                         \
    )                                                   \

#define PLANAR_DEFINE_ELEMENT_COMPONENT_GET_SET_DRAG_2( \
    component, type, name)                              \
    PLANAR_DEFINE_GET_SET_RAW(component, type, name,    \
        return name.get_value();,                       \
                                                        \
        name.set_value(new_##name.get_array());         \
    )                                                   \
