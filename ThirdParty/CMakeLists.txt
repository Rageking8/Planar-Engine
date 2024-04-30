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
    URL https://github.com/ocornut/imgui/archive/refs/tags/v1.90.5.zip
    URL_HASH
        SHA256=8860AA37506D7E16CF093BA26FA51C2BBD48ADDCC389D3B315BF690F66D709E4
)

FetchContent_Declare(
    yaml-cpp
    URL https://github.com/jbeder/yaml-cpp/archive/refs/tags/0.8.0.zip
    URL_HASH
        SHA256=334E80AB7B52E14C23F94E041C74BAB0742F2281AAD55F66BE2F19F4B7747071
)

add_subdirectory(glad)
add_subdirectory(GLFW)
add_subdirectory(ImGui)
add_subdirectory(KHR)
add_subdirectory(yaml-cpp)
