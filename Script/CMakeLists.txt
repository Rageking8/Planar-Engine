add_executable(${PLANAR_SCRIPT_TARGET})

target_compile_options(${PLANAR_SCRIPT_TARGET} PRIVATE
    "/langversion:12.0"
)

if(MSVC)
    set_target_properties(${PLANAR_SCRIPT_TARGET} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY
        ${CMAKE_BINARY_DIR}/Script/$<0:>
    )
endif()

add_subdirectory(Planar)
