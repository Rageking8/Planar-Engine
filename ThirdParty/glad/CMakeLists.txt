add_library(glad STATIC
    gl.h
    gl.c
)

target_include_directories(glad PRIVATE
    ..
    ${PLANAR_EXTERNAL_INCLUDE_DIR}
)

file(COPY gl.h DESTINATION
    ${PLANAR_EXTERNAL_THIRD_PARTY_INCLUDE_DIR}/glad
)
