#pragma once

#include "Planar/Engine/Export/ExportMacros.hpp"
#include "Planar/Engine/Core/Utils/Macros/RepeatMacros.hpp"
#include "Planar/Engine/Core/FileSystem/FileSystem.hpp"

#include <cstddef>

#define PLANAR_LOAD_STD_STRING_ASSET(ns, name) \
    namespace Planar::Asset::ns                \
    {                                          \
        extern const std::string name;         \
    }                                          \

#define PLANAR_LOAD_STD_STRING_ASSET_USING_IMPORT(ns, name) \
    namespace Planar::Asset::ns                             \
    {                                                       \
        PLANAR_API extern const std::string name;           \
    }                                                       \

#define PLANAR_LOAD_UNSIGNED_CHAR_ARRAY_ASSET(ns, name) \
    namespace Planar::Asset::ns                         \
    {                                                   \
        extern const unsigned char name[];              \
        extern const std::size_t name##_length;         \
    }                                                   \

#define PLANAR_LOAD_UNSIGNED_CHAR_ARRAY_ASSET_SINGLE_CHUNK( \
    ns, name, chunk_id)                                     \
    namespace Planar::Asset::ns                             \
    {                                                       \
        extern const unsigned char name##chunk_id[];        \
        extern const std::size_t name##chunk_id##_length;   \
    }                                                       \

#define PLANAR_LOAD_UNSIGNED_CHAR_ARRAY_ASSET_ALL_CHUNKS(   \
    ns, name)                                               \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER(               \
        PLANAR_ASSET_INCLUDE_##name,                        \
        PLANAR_LOAD_UNSIGNED_CHAR_ARRAY_ASSET_SINGLE_CHUNK, \
        ns, name)                                           \

#define PLANAR_APPEND_ARRAY_TO_FILE(path, ns, name)         \
    Planar::Engine::Core::FileSystem::append_array_to_file( \
        path, Planar::Asset::ns::name,                      \
        Planar::Asset::ns::name##_length);                  \

#define PLANAR_APPEND_SINGLE_CHUNK_TO_FILE(path, ns, name,  \
    chunk_id)                                               \
    Planar::Engine::Core::FileSystem::append_array_to_file( \
        path, Planar::Asset::ns::name##chunk_id,            \
        Planar::Asset::ns::name##chunk_id##_length);        \

#define PLANAR_APPEND_ALL_CHUNKS_TO_FILE(path, ns, name) \
    PLANAR_REPEAT_MACRO_WITH_TRAILING_NUMBER(            \
        PLANAR_ASSET_INCLUDE_##name,                     \
        PLANAR_APPEND_SINGLE_CHUNK_TO_FILE,              \
        path, ns, name)                                  \
