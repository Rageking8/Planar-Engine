add_library(${PLANAR_ENGINE_TARGET} SHARED)

target_link_libraries(${PLANAR_ENGINE_TARGET} PRIVATE
    glfw
    glad
    imgui
    yaml-cpp
    stb
)

target_include_directories(${PLANAR_ENGINE_TARGET} PRIVATE
    ${PLANAR_INCLUDE_ROOT_DIR}
    ${PLANAR_EXTERNAL_INCLUDE_DIR}
)

if(MSVC)
    target_compile_options(${PLANAR_ENGINE_TARGET} PRIVATE
        /Zc:preprocessor
    )
endif()

define_if_target_shared(${PLANAR_ENGINE_TARGET} PRIVATE
    PLANAR_ENABLE_EXPORT
    PLANAR_EXPORT_SOURCE
)

add_custom_command(TARGET ${PLANAR_ENGINE_TARGET} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PLANAR_ENGINE_TARGET}>
    ${CMAKE_BINARY_DIR}/Source/Planar/Editor

    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PLANAR_ENGINE_TARGET}>
    ${CMAKE_BINARY_DIR}/Script
)

add_subdirectory(Asset)
add_subdirectory(Core)
add_subdirectory(Export)
add_subdirectory(Graphics)
add_subdirectory(Scene)
add_subdirectory(UI)
