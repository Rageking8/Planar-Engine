add_library(glad STATIC
    gl.h
    gl.c
)

target_include_directories(glad PRIVATE
    ..
    ${PLANAR_EXTERNAL_INCLUDES_DIR}
)

file(COPY gl.h DESTINATION
    "${PLANAR_EXTERNAL_THIRD_PARTY_INCLUDES_DIR}/glad"
)
