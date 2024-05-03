add_executable(${PLANAR_EDITOR_TARGET})

target_link_libraries(${PLANAR_EDITOR_TARGET} PRIVATE
    ${PLANAR_ENGINE_TARGET}
)

target_include_directories(${PLANAR_EDITOR_TARGET} PRIVATE
    ${PLANAR_INCLUDE_ROOT_DIR}
    ${PLANAR_EXTERNAL_INCLUDE_DIR}
)

define_if_check_target_shared(${PLANAR_EDITOR_TARGET}
    ${PLANAR_ENGINE_TARGET} PRIVATE
    PLANAR_ENABLE_EXPORT
)

add_subdirectory(Entry)
add_subdirectory(Scene)
