cmake_minimum_required(VERSION 3.15..3.29 FATAL_ERROR)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMake)
include(GetAllTargetList)

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

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY
    VS_STARTUP_PROJECT ${PLANAR_EDITOR_TARGET}
)

add_subdirectory(Source)
add_subdirectory(Include)
add_subdirectory(ThirdParty)

get_all_target_list(PLANAR_ALL_TARGETS)
set_target_properties(${PLANAR_ALL_TARGETS} PROPERTIES FOLDER ThirdParty)
set_target_properties(${PLANAR_CORE_TARGET} ${PLANAR_EDITOR_TARGET}
    PROPERTIES FOLDER Planar
)
