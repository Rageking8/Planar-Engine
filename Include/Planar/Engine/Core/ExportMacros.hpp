#pragma once

#if defined(_WIN32) && defined(PLANAR_ENABLE_EXPORT)
    #ifdef PLANAR_EXPORT_SOURCE
        #define PLANAR_API __declspec(dllexport)
    #else
        #define PLANAR_API __declspec(dllimport)
    #endif
#else
    #define PLANAR_API
#endif

// Export prototypes

#define PLANAR_EXPORT_FUNCTION_PROTOTYPE(name, return_type, ...) \
    extern "C" PLANAR_API return_type name(__VA_ARGS__)          \

#define PLANAR_EXPORT_HANDLE_FUNCTION_PROTOTYPE(name, return_type, ...) \
    PLANAR_EXPORT_FUNCTION_PROTOTYPE(name, return_type, void* handle    \
        __VA_OPT__(,) __VA_ARGS__)                                      \

#define PLANAR_EXPORT_CONSTRUCT_PROTOTYPE(namespace_prefix)        \
    PLANAR_EXPORT_FUNCTION_PROTOTYPE(namespace_prefix##_construct, \
        void*)                                                     \

#define PLANAR_EXPORT_DESTRUCT_PROTOTYPE(namespace_prefix)               \
    PLANAR_EXPORT_HANDLE_FUNCTION_PROTOTYPE(namespace_prefix##_destruct, \
        void)                                                            \

// Export declares

#define PLANAR_EXPORT_DECLARE_FUNCTION(name, return_type, ...)        \
    PLANAR_EXPORT_FUNCTION_PROTOTYPE(name, return_type, __VA_ARGS__); \

#define PLANAR_EXPORT_DECLARE_HANDLE_FUNCTION(name, return_type, ...) \
    PLANAR_EXPORT_HANDLE_FUNCTION_PROTOTYPE(name, return_type,        \
        __VA_ARGS__);                                                 \

#define PLANAR_EXPORT_DECLARE_CONSTRUCT(namespace_prefix) \
    PLANAR_EXPORT_CONSTRUCT_PROTOTYPE(namespace_prefix);  \

#define PLANAR_EXPORT_DECLARE_DESTRUCT(namespace_prefix) \
    PLANAR_EXPORT_DESTRUCT_PROTOTYPE(namespace_prefix);  \

#define PLANAR_EXPORT_DECLARE_CONSTRUCT_DESTRUCT(namespace_prefix) \
    PLANAR_EXPORT_DECLARE_CONSTRUCT(namespace_prefix)              \
    PLANAR_EXPORT_DECLARE_DESTRUCT(namespace_prefix)               \

// Export defines

#define PLANAR_EXPORT_DEFINE_CONSTRUCT(namespace_prefix, type) \
    PLANAR_EXPORT_CONSTRUCT_PROTOTYPE(namespace_prefix)        \
    {                                                          \
        return new type;                                       \
    }                                                          \

#define PLANAR_EXPORT_DEFINE_DESTRUCT(namespace_prefix) \
    PLANAR_EXPORT_DESTRUCT_PROTOTYPE(namespace_prefix)  \
    {                                                   \
        delete handle;                                  \
    }                                                   \

#define PLANAR_EXPORT_DEFINE_CONSTRUCT_DESTRUCT(namespace_prefix, type) \
    PLANAR_EXPORT_DEFINE_CONSTRUCT(namespace_prefix, type)              \
    PLANAR_EXPORT_DEFINE_DESTRUCT(namespace_prefix)                     \

#define PLANAR_EXPORT_DEFINE_HANDLE_FUNCTION(namespace_prefix, name,   \
    return_type, arg_type1, arg1, type)                                \
    PLANAR_EXPORT_HANDLE_FUNCTION_PROTOTYPE(namespace_prefix##_##name, \
        return_type, arg_type1)                                        \
    {                                                                  \
        static_cast<type*>(handle)->name(arg1);                        \
    }                                                                  \
