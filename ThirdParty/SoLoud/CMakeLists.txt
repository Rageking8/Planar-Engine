message(STATUS "Fetching SoLoud")

set(SOLOUD_BACKEND_SDL2 OFF CACHE BOOL "" FORCE)
set(SOLOUD_BACKEND_WASAPI ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(soloud)

add_subdirectory(${soloud_SOURCE_DIR}/contrib ${soloud_BINARY_DIR})

copy_single_source(
    ${soloud_SOURCE_DIR}/include/
    ${PLANAR_EXTERNAL_THIRD_PARTY_INCLUDE_DIR}/SoLoud
)

set_property(TARGET soloud PROPERTY
    MSVC_RUNTIME_LIBRARY MultiThreaded$<$<CONFIG:Debug>:Debug>
)
