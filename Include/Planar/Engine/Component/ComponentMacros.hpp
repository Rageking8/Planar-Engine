#pragma once

#include "Planar/Engine/Core/Utils/Macros/MacroOverload.hpp"
#include "Planar/Engine/Component/ComponentType.hpp"

#define PLANAR_DEFINE_COMPONENT_TYPE_AND_NAME(type)            \
    static constexpr ComponentType TYPE = ComponentType::type; \
    static constexpr const char* NAME = #type;                 \

#define PLANAR_DEFINE_COMPONENT(...)                     \
    PLANAR_DEFINE_MACRO_OVERLOAD(PLANAR_DEFINE_COMPONENT \
        __VA_OPT__(,) __VA_ARGS__)                       \

#define PLANAR_DEFINE_COMPONENT1(type)        \
    PLANAR_DEFINE_COMPONENT2(type, Component) \

#define PLANAR_DEFINE_COMPONENT2(type, parent)             \
    using Parent = parent;                                 \
    PLANAR_DEFINE_COMPONENT_TYPE_AND_NAME(type)            \
                                                           \
    virtual ComponentType get_type() const override        \
    {                                                      \
        return TYPE;                                       \
    }                                                      \
                                                           \
    virtual bool match(ComponentType other) const override \
    {                                                      \
        if (other == TYPE)                                 \
        {                                                  \
            return true;                                   \
        }                                                  \
                                                           \
        return Parent::match(other);                       \
    }                                                      \
