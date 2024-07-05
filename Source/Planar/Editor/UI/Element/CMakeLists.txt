target_sources(${PLANAR_EDITOR_TARGET} PRIVATE
    CameraController2D.cpp
    Camera2D.cpp
    ComponentBase.cpp
    PlayStopToggle.cpp
    ProgressDisplay.cpp
    Transform2D.cpp
)

add_subdirectory(Component)
