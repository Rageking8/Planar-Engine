planar_message(STATUS "Fetching ImGui")

FetchContent_MakeAvailable(imgui)

set(IMGUI_HEADERS_LIST
    imgui.h
    misc/cpp/imgui_stdlib.h
    backends/imgui_impl_glfw.h
    backends/imgui_impl_opengl3.h
)
list(TRANSFORM IMGUI_HEADERS_LIST PREPEND ${imgui_SOURCE_DIR}/)
file(COPY ${IMGUI_HEADERS_LIST} DESTINATION
    ${PLANAR_EXTERNAL_THIRD_PARTY_INCLUDE_DIR}/ImGui
)
copy_single_source(
    ${imgui_SOURCE_DIR}/imconfig.h
    ${PLANAR_EXTERNAL_INCLUDE_DIR}
)

set(IMGUI_SOURCES_LIST
    imgui.cpp
    imgui_draw.cpp
    imgui_tables.cpp
    imgui_widgets.cpp
    misc/cpp/imgui_stdlib.cpp
    backends/imgui_impl_glfw.cpp
    backends/imgui_impl_opengl3.cpp
)
list(TRANSFORM IMGUI_SOURCES_LIST PREPEND ${imgui_SOURCE_DIR}/)

add_library(imgui STATIC
    ${IMGUI_HEADERS_LIST}
    ${IMGUI_SOURCES_LIST}
)

set_property(TARGET imgui PROPERTY
    MSVC_RUNTIME_LIBRARY MultiThreaded$<$<CONFIG:Debug>:Debug>
)

target_include_directories(imgui PRIVATE
    ${imgui_SOURCE_DIR}
    ${GLFW_SOURCE_DIR}/include
)
