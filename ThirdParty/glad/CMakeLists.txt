include(FileUtils)

add_library(glad STATIC
    gl.h
    gl.c
)

target_include_directories(glad PRIVATE
    ..
    ${PLANAR_EXTERNAL_INCLUDE_DIR}
)

set_property(TARGET glad PROPERTY
    MSVC_RUNTIME_LIBRARY MultiThreaded$<$<CONFIG:Debug>:Debug>
)

copy_single_source(
    gl.h
    ${PLANAR_EXTERNAL_THIRD_PARTY_INCLUDE_DIR}/glad
)
