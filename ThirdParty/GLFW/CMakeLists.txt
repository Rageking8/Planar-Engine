planar_message(STATUS "Fetching GLFW")

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(glfw)

copy_single_source(
    ${GLFW_SOURCE_DIR}/include/GLFW/
    ${PLANAR_EXTERNAL_THIRD_PARTY_INCLUDE_DIR}/GLFW
)

set_property(TARGET glfw PROPERTY
    MSVC_RUNTIME_LIBRARY MultiThreaded$<$<CONFIG:Debug>:Debug>
)
