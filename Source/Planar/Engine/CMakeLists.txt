add_library(${PLANAR_ENGINE_OBJECT_TARGET} OBJECT)

add_dependencies(${PLANAR_ENGINE_OBJECT_TARGET}
    ${PLANAR_SCRIPT_TARGET}
)

set_property(TARGET ${PLANAR_ENGINE_OBJECT_TARGET} PROPERTY
    MSVC_RUNTIME_LIBRARY MultiThreaded$<$<CONFIG:Debug>:Debug>
)

add_library(${PLANAR_ENGINE_STATIC_TARGET} STATIC
    $<TARGET_OBJECTS:${PLANAR_ENGINE_OBJECT_TARGET}>
)

target_compile_definitions(${PLANAR_ENGINE_OBJECT_TARGET} PRIVATE
    PLANAR_ENABLE_EXPORT
    PLANAR_EXPORT_SOURCE
)

if(WIN32)
    target_compile_definitions(${PLANAR_ENGINE_OBJECT_TARGET} PRIVATE
        WIN32_LEAN_AND_MEAN
    )
endif()

add_library(${PLANAR_ENGINE_SHARED_TARGET} SHARED
    $<TARGET_OBJECTS:${PLANAR_ENGINE_OBJECT_TARGET}>
)

set(PLANAR_ENGINE_LINK_LIBRARIES
    glfw
    glad
    imgui
    yaml-cpp
    stb
    nfd
    soloud
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

    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_BINARY_DIR}/Script/PlanarScript.dll
    ${CMAKE_BINARY_DIR}/Asset

    COMMAND ${CMAKE_COMMAND}
    -DPLANAR_EDITOR_TARGET=${PLANAR_EDITOR_TARGET}
    -DPLANAR_SOURCE_DIR=${CMAKE_SOURCE_DIR}
    -DPLANAR_CURRENT_SOURCE_DIR=${CMAKE_SOURCE_DIR}/Asset/Editor
    -DPLANAR_CURRENT_BINARY_DIR=${CMAKE_BINARY_DIR}/Asset/Editor
    -DPLANAR_ROOT_ASSET_DIR=${PLANAR_ROOT_ASSET_DIR}
    -DPLANAR_ASSET_INCLUDE_DIR=${PLANAR_ASSET_INCLUDE_DIR}
    -DPLANAR_CMAKE_FUNCTION_LOG=${PLANAR_CMAKE_FUNCTION_LOG} -P
    ${CMAKE_SOURCE_DIR}/Asset/Editor/PackPlanarEngine.cmake

    COMMAND ${CMAKE_COMMAND}
    -DPLANAR_EDITOR_TARGET=${PLANAR_EDITOR_TARGET}
    -DPLANAR_SOURCE_DIR=${CMAKE_SOURCE_DIR}
    -DPLANAR_CURRENT_SOURCE_DIR=${CMAKE_SOURCE_DIR}/Asset/Editor/Script
    -DPLANAR_CURRENT_BINARY_DIR=${CMAKE_BINARY_DIR}/Asset/Editor/Script
    -DPLANAR_ROOT_ASSET_DIR=${PLANAR_ROOT_ASSET_DIR}
    -DPLANAR_ASSET_INCLUDE_DIR=${PLANAR_ASSET_INCLUDE_DIR}
    -DPLANAR_CMAKE_FUNCTION_LOG=${PLANAR_CMAKE_FUNCTION_LOG} -P
    ${CMAKE_SOURCE_DIR}/Asset/Editor/Script/PackPlanarScript.cmake
)

add_subdirectory(Asset)
add_subdirectory(Audio)
add_subdirectory(Component)
add_subdirectory(Core)
add_subdirectory(Export)
add_subdirectory(GameObject)
add_subdirectory(Graphics)
add_subdirectory(Math)
add_subdirectory(Scene)
add_subdirectory(Script)
add_subdirectory(UI)
