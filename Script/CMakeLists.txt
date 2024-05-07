add_executable(${PLANAR_SCRIPT_TARGET})

target_compile_options(${PLANAR_SCRIPT_TARGET} PRIVATE
    "/langversion:12.0"
)

target_sources(${PLANAR_SCRIPT_TARGET} PRIVATE
    Main.cs
)
