add_library(${PLANAR_ENGINE_TARGET} SHARED)

target_link_libraries(${PLANAR_ENGINE_TARGET} PRIVATE
    glfw
    glad
    imgui
)

target_include_directories(${PLANAR_ENGINE_TARGET} PRIVATE
    ${PLANAR_INCLUDE_ROOT_DIR}
    ${PLANAR_EXTERNAL_INCLUDE_DIR}
)

define_if_target_shared(${PLANAR_ENGINE_TARGET} PRIVATE
    PLANAR_ENABLE_EXPORT
    PLANAR_EXPORT_SOURCE
)

add_subdirectory(Core)
add_subdirectory(Graphics)
