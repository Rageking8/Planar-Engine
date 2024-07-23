message(STATUS "Fetching SoLoud")

set(SOLOUD_BACKEND_SDL2 OFF CACHE BOOL "" FORCE)
set(SOLOUD_BACKEND_WASAPI ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(soloud)

set(CMAKE_WARN_DEPRECATED OFF CACHE BOOL "" FORCE)
set(CMAKE_PROJECT_INCLUDE_BEFORE
    ${PLANAR_SOURCE_DIR}/CMake/SetCMP0048New.cmake
)
add_subdirectory(${soloud_SOURCE_DIR}/contrib ${soloud_BINARY_DIR})
unset(CMAKE_PROJECT_INCLUDE_BEFORE)
set(CMAKE_WARN_DEPRECATED ON CACHE BOOL "" FORCE)

copy_single_source(
    ${soloud_SOURCE_DIR}/include/
    ${PLANAR_EXTERNAL_THIRD_PARTY_INCLUDE_DIR}/SoLoud
)

set_property(TARGET soloud PROPERTY
    MSVC_RUNTIME_LIBRARY MultiThreaded$<$<CONFIG:Debug>:Debug>
)
