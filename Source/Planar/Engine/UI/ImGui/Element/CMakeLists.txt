target_sources(${PLANAR_ENGINE_OBJECT_TARGET} PRIVATE
    Button.cpp
    Checkbox.cpp
    DropDown.cpp
    Element.cpp
    InputField.cpp
    IntSlider.cpp
    ProgressBar.cpp
    Tree.cpp
)

add_subdirectory(Button)
add_subdirectory(Drag)
