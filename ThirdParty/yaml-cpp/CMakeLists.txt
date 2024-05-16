message(STATUS "Fetching yaml-cpp")

set(CMAKE_WARN_DEPRECATED OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(yaml-cpp)

set(CMAKE_WARN_DEPRECATED ON CACHE BOOL "" FORCE)

copy_single_source(
    ${yaml-cpp_SOURCE_DIR}/include/yaml-cpp/
    ${PLANAR_EXTERNAL_THIRD_PARTY_INCLUDE_DIR}/yaml-cpp
)

target_link_options(${PLANAR_ENGINE_TARGET} PRIVATE
    /NATVIS:${yaml-cpp_SOURCE_DIR}/src/contrib/yaml-cpp.natvis
)
