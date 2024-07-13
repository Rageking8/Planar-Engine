message(STATUS "Fetching stb")

FetchContent_MakeAvailable(stb)

copy_single_source(
    ${stb_SOURCE_DIR}/stb_image.h
    ${PLANAR_EXTERNAL_THIRD_PARTY_INCLUDE_DIR}/stb
)

set(STB_HEADERS_LIST
    stb_image.h
)
list(TRANSFORM STB_HEADERS_LIST PREPEND ${stb_SOURCE_DIR}/)

file(WRITE ${stb_SOURCE_DIR}/stb_image.cpp
[=[
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
]=]
)

set(STB_SOURCES_LIST
    stb_image.cpp
)
list(TRANSFORM STB_SOURCES_LIST PREPEND ${stb_SOURCE_DIR}/)

add_library(stb STATIC
    ${STB_HEADERS_LIST}
    ${STB_SOURCES_LIST}
)

set_property(TARGET stb PROPERTY
    MSVC_RUNTIME_LIBRARY MultiThreaded$<$<CONFIG:Debug>:Debug>
)
