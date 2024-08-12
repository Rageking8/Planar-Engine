target_sources(${PLANAR_EDITOR_TARGET} PRIVATE
    Editor.cpp
)

add_subdirectory(Archive)
add_subdirectory(Input)
add_subdirectory(Progress)
add_subdirectory(Save)
add_subdirectory(Select)
add_subdirectory(VisualStudio)
