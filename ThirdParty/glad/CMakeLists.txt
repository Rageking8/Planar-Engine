include(FileUtils)

add_library(glad STATIC
    gl.h
    gl.c
)

target_include_directories(glad PRIVATE
    ..
    ${PLANAR_EXTERNAL_INCLUDE_DIR}
)

copy_single_source(
    gl.h
    ${PLANAR_EXTERNAL_THIRD_PARTY_INCLUDE_DIR}/glad
)
