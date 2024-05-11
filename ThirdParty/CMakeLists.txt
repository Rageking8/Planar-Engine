include(FetchContent)

if(POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
endif()

set(PLANAR_EXTERNAL_THIRD_PARTY_INCLUDE_DIR
    ${PLANAR_EXTERNAL_INCLUDE_DIR}/ThirdParty
)

FetchContent_Declare(
    glfw
    URL https://github.com/glfw/glfw/archive/refs/tags/3.4.zip
    URL_HASH
        SHA256=A133DDC3D3C66143EBA9035621DB8E0BCF34DBA1EE9514A9E23E96AFD39FD57A
)

FetchContent_Declare(
    imgui
    URL https://github.com/ocornut/imgui/archive/refs/tags/v1.90.6-docking.zip
    URL_HASH
        SHA256=AD0BC8172F2B6405A32FAFAFADDE8A38C7B7EEA8AC490CADE10160BFDCAC7241
)

FetchContent_Declare(
    yaml-cpp
    URL https://github.com/jbeder/yaml-cpp/archive/refs/tags/0.8.0.zip
    URL_HASH
        SHA256=334E80AB7B52E14C23F94E041C74BAB0742F2281AAD55F66BE2F19F4B7747071
)

FetchContent_Declare(
    stb
    URL https://github.com/nothings/stb/archive/ae721c50eaf761660b4f90cc590453cdb0c2acd0.zip
    URL_HASH
        SHA256=5D075769721E676746D0C25B698A0F00741F68252F9AB4B7EE245C513AEEC3DE
)

add_subdirectory(glad)
add_subdirectory(GLFW)
add_subdirectory(ImGui)
add_subdirectory(KHR)
add_subdirectory(stb)
add_subdirectory(yaml-cpp)
