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

#define PLANAR_DECLARE_CONSTRUCT(namespace_prefix)   \
    PLANAR_API void* namespace_prefix##_construct(); \

#define PLANAR_DECLARE_DESTRUCT(namespace_prefix)              \
    PLANAR_API void namespace_prefix##_destruct(void* handle); \

#define PLANAR_DECLARE_CONSTRUCT_DESTRUCT(namespace_prefix) \
    PLANAR_DECLARE_CONSTRUCT(namespace_prefix)              \
    PLANAR_DECLARE_DESTRUCT(namespace_prefix)               \

#define PLANAR_DEFINE_CONSTRUCT(namespace_prefix, type) \
    void* namespace_prefix##_construct()                \
    {                                                   \
        return new type;                                \
    }                                                   \

#define PLANAR_DEFINE_DESTRUCT(namespace_prefix)   \
    void namespace_prefix##_destruct(void* handle) \
    {                                              \
        delete handle;                             \
    }                                              \

#define PLANAR_DEFINE_CONSTRUCT_DESTRUCT(namespace_prefix, type) \
    PLANAR_DEFINE_CONSTRUCT(namespace_prefix, type)              \
    PLANAR_DEFINE_DESTRUCT(namespace_prefix)                     \
