cmake_minimum_required(VERSION 3.15..3.29 FATAL_ERROR)

project(Planar VERSION 0.1.0 LANGUAGES C CXX)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PLANAR_EXTERNAL_INCLUDES_DIR
    "${CMAKE_BINARY_DIR}/External/Includes"
)
set(PLANAR_EDITOR_TARGET PlanarEditor)

add_executable(${PLANAR_EDITOR_TARGET})

target_link_libraries(${PLANAR_EDITOR_TARGET} PRIVATE
    glfw
    glad
    imgui
)

target_include_directories(${PLANAR_EDITOR_TARGET} PRIVATE
    ${PLANAR_EXTERNAL_INCLUDES_DIR}
)

add_custom_command(TARGET ${PLANAR_EDITOR_TARGET} POST_BUILD COMMAND
    ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PLANAR_EDITOR_TARGET}>
    $<TARGET_RUNTIME_DLLS:${PLANAR_EDITOR_TARGET}>
    $<TARGET_FILE_DIR:${PLANAR_EDITOR_TARGET}> COMMAND_EXPAND_LISTS
)

if(MSVC)
    target_compile_options(${PLANAR_EDITOR_TARGET} PRIVATE /W4)
endif()

add_subdirectory(Planar)
add_subdirectory(ThirdParty)
