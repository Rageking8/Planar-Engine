#pragma once

#define PLANAR_BIND_MEMBER_FUNCTION(member_function) \
    [this]                                           \
    {                                                \
        member_function();                           \
    }                                                \

#define PLANAR_BIND_MEMBER_FUNCTION_ARG1(member_function) \
    [this](auto param1)                                   \
    {                                                     \
        member_function(param1);                          \
    }                                                     \

#define PLANAR_BIND_MEMBER_FUNCTION_ARG2(member_function) \
    [this](auto param1, auto param2)                      \
    {                                                     \
        member_function(param1, param2);                  \
    }                                                     \
