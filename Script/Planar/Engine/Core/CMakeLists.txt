target_sources(${PLANAR_SCRIPT_TARGET} PRIVATE
    Application.cs
    ApplicationAsset.cs
    Entry.cs
    ImportConstants.cs
)

add_subdirectory(Log)
add_subdirectory(Native)
add_subdirectory(Utils)
