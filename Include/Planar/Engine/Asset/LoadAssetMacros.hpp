#pragma once

#define PLANAR_LOAD_STD_STRING_ASSET(ns, name) \
    namespace Planar::Asset::ns                \
    {                                          \
        extern const std::string name;         \
    }
