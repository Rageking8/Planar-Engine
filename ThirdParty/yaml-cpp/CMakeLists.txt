message(STATUS "Fetching yaml-cpp")

FetchContent_MakeAvailable(yaml-cpp)

copy_single_source(
    ${yaml-cpp_SOURCE_DIR}/include/yaml-cpp/
    ${PLANAR_EXTERNAL_THIRD_PARTY_INCLUDE_DIR}/yaml-cpp
)
