#pragma once

#define PLANAR_GET_FUNCTION_NAME(_0, _1, _2, _3, _4, _5, _6, \
    _7, _8, _9, _10, _11, _12, name, ...) name               \

// Supports argument length of range [0, 12]
// Create overloaded macro:
//
//     #define MY_MACRO(...)                                                \
//         PLANAR_DEFINE_MACRO_OVERLOAD(MY_MACRO __VA_OPT__(,) __VA_ARGS__) \
//
// Define overloads by appending the number of parameters to the macro name:
//
//     #define MY_MACRO1(param1) ...
//     #define MY_MACRO2(param1, param2) ...
//
// Invoke the overloaded macro:
//
//     MY_MACRO(arg1)
//     MY_MACRO(arg1, arg2)
//
#define PLANAR_DEFINE_MACRO_OVERLOAD(name, ...)                      \
    PLANAR_GET_FUNCTION_NAME(_0 __VA_OPT__(,) __VA_ARGS__, name##12, \
        name##11, name##10, name##9, name##8, name##7, name##6,      \
        name##5, name##4, name##3, name##2, name##1, name##0)        \
        (__VA_ARGS__)                                                \
