add_library(${PLANAR_CORE_TARGET} STATIC)

target_include_directories(${PLANAR_CORE_TARGET} PRIVATE
    ${PLANAR_INCLUDE_ROOT_DIR}
    ${PLANAR_EXTERNAL_INCLUDES_DIR}
)

target_sources(${PLANAR_CORE_TARGET} PRIVATE
    GLFWContext.cpp
)
