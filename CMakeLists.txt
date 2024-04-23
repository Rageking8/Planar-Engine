cmake_minimum_required(VERSION 3.15..3.29 FATAL_ERROR)

project(Planar VERSION 0.1.0 LANGUAGES C CXX)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PLANAR_INCLUDE_ROOT_DIR
    "${CMAKE_CURRENT_SOURCE_DIR}/Include"
)
set(PLANAR_EXTERNAL_INCLUDE_DIR
    "${CMAKE_BINARY_DIR}/External/Include"
)

set(PLANAR_CORE_TARGET PlanarCore)
set(PLANAR_EDITOR_TARGET PlanarEditor)

add_subdirectory(Source)
add_subdirectory(Include)
add_subdirectory(ThirdParty)
