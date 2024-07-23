planar_message(STATUS "Fetching yaml-cpp")

set(CMAKE_WARN_DEPRECATED OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(yaml-cpp)

set(CMAKE_WARN_DEPRECATED ON CACHE BOOL "" FORCE)

copy_single_source(
    ${yaml-cpp_SOURCE_DIR}/include/yaml-cpp/
    ${PLANAR_EXTERNAL_INCLUDE_DIR}/yaml-cpp
)
copy_single_source(
    ${yaml-cpp_SOURCE_DIR}/include/yaml-cpp/
    ${PLANAR_EXTERNAL_THIRD_PARTY_INCLUDE_DIR}/yaml-cpp
)

set_property(TARGET yaml-cpp PROPERTY
    MSVC_RUNTIME_LIBRARY MultiThreaded$<$<CONFIG:Debug>:Debug>
)

target_link_options(${PLANAR_ENGINE_OBJECT_TARGET} PRIVATE
    /NATVIS:${yaml-cpp_SOURCE_DIR}/src/contrib/yaml-cpp.natvis
)

target_compile_definitions(${PLANAR_ENGINE_OBJECT_TARGET} PRIVATE
    YAML_CPP_STATIC_DEFINE
)

target_compile_definitions(${PLANAR_EDITOR_TARGET} PRIVATE
    YAML_CPP_STATIC_DEFINE
)
