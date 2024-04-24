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
