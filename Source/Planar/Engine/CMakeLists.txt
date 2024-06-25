add_library(${PLANAR_ENGINE_OBJECT_TARGET} OBJECT)

add_library(${PLANAR_ENGINE_STATIC_TARGET} STATIC
    $<TARGET_OBJECTS:${PLANAR_ENGINE_OBJECT_TARGET}>
)

target_compile_definitions(${PLANAR_ENGINE_OBJECT_TARGET} PRIVATE
    PLANAR_ENABLE_EXPORT
    PLANAR_EXPORT_SOURCE
)

add_library(${PLANAR_ENGINE_SHARED_TARGET} SHARED
    $<TARGET_OBJECTS:${PLANAR_ENGINE_OBJECT_TARGET}>
)

set(PLANAR_ENGINE_LINK_LIBRARIES
    glfw
    glad
    imgui
    yaml-cpp
    stb
    reproc++
)

target_link_libraries(${PLANAR_ENGINE_STATIC_TARGET} PRIVATE
    ${PLANAR_ENGINE_LINK_LIBRARIES}
)
target_link_libraries(${PLANAR_ENGINE_SHARED_TARGET} PRIVATE
    ${PLANAR_ENGINE_LINK_LIBRARIES}
)

set_target_properties(${PLANAR_ENGINE_SHARED_TARGET} PROPERTIES
    OUTPUT_NAME PlanarEngine
)

target_include_directories(${PLANAR_ENGINE_OBJECT_TARGET} PRIVATE
    ${PLANAR_INCLUDE_ROOT_DIR}
    ${PLANAR_EXTERNAL_INCLUDE_DIR}
)

if(MSVC)
    target_compile_options(${PLANAR_ENGINE_OBJECT_TARGET} PRIVATE
        /Zc:preprocessor
    )
endif()

add_custom_command(TARGET ${PLANAR_ENGINE_SHARED_TARGET} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:${PLANAR_ENGINE_SHARED_TARGET}>
    ${CMAKE_BINARY_DIR}/Source/Planar/Editor

    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:${PLANAR_ENGINE_SHARED_TARGET}>
    ${CMAKE_BINARY_DIR}/Script

    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:${PLANAR_ENGINE_SHARED_TARGET}>
    ${CMAKE_BINARY_DIR}/Asset
)

add_subdirectory(Asset)
add_subdirectory(Component)
add_subdirectory(Core)
add_subdirectory(Export)
add_subdirectory(Graphics)
add_subdirectory(Scene)
add_subdirectory(UI)
