target_sources(${PLANAR_EDITOR_TARGET} PRIVATE
    Editor.hpp
    EditorGameMode.hpp
)

add_subdirectory(Archive)
add_subdirectory(Input)
add_subdirectory(Progress)
add_subdirectory(Save)
add_subdirectory(Select)
add_subdirectory(Utils)
add_subdirectory(VisualStudio)
