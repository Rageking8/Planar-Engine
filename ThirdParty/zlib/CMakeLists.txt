message(STATUS "Fetching zlib")

set(ZLIB_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(zlib)

add_library(ZLIB::ZLIB ALIAS zlibstatic)
