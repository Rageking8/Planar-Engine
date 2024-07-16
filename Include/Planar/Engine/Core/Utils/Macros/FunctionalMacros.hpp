#pragma once

#define PLANAR_CAPTURE_THIS(callable) \
    [this]                            \
    {                                 \
        callable();                   \
    }                                 \

#define PLANAR_CAPTURE_THIS_PARAM1(callable) \
    [this](auto param1)                      \
    {                                        \
        callable(param1);                    \
    }                                        \

#define PLANAR_CAPTURE_THIS_PARAM1_RET(callable) \
    [this](auto param1)                          \
    {                                            \
        return callable(param1);                 \
    }                                            \

#define PLANAR_CAPTURE_THIS_PARAM2(callable) \
    [this](auto param1, auto param2)         \
    {                                        \
        callable(param1, param2);            \
    }                                        \

#define PLANAR_CAPTURE_REF(callable) \
    [&]                              \
    {                                \
        callable();                  \
    }                                \

#define PLANAR_CAPTURE_REF_ARG1(callable, arg1) \
    [&]                                         \
    {                                           \
        callable(arg1);                         \
    }                                           \
