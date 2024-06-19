#pragma once

#define PLANAR_CAPTURE_THIS(callable) \
    [this]                            \
    {                                 \
        callable();                   \
    }                                 \

#define PLANAR_CAPTURE_THIS_ARG1(callable) \
    [this](auto param1)                    \
    {                                      \
        callable(param1);                  \
    }                                      \

#define PLANAR_CAPTURE_THIS_ARG2(callable) \
    [this](auto param1, auto param2)       \
    {                                      \
        callable(param1, param2);          \
    }                                      \
