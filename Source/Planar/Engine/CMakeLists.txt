add_library(${PLANAR_ENGINE_TARGET} STATIC)

target_include_directories(${PLANAR_ENGINE_TARGET} PRIVATE
    ${PLANAR_INCLUDE_ROOT_DIR}
    ${PLANAR_EXTERNAL_INCLUDE_DIR}
)

add_subdirectory(Core)
add_subdirectory(Graphics)
