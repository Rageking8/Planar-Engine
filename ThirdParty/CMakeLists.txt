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

FetchContent_Declare(
    dotnet-sdk
    URL https://download.visualstudio.microsoft.com/download/pr/6dd60d95-f5ae-414e-8259-b2a115e51714/c56f08471133d789dee9ffa52ddf5c1e/dotnet-sdk-8.0.300-win-x64.zip
    URL_HASH
        SHA256=A3B8874666A66B425396E144B78514E8BB0BD2E3DC9B715F6A81623CB395DFF2
)

FetchContent_Declare(
    zlib
    URL https://github.com/madler/zlib/archive/refs/tags/v1.3.1.zip
    URL_HASH
        SHA256=50B24B47BF19E1F35D2A21FF36D2A366638CDF958219A66F30CE0861201760E6
    OVERRIDE_FIND_PACKAGE
)

FetchContent_Declare(
    libzip
    URL https://github.com/nih-at/libzip/archive/refs/tags/v1.10.1.zip
    URL_HASH
        SHA256=FFDF7427E848DF6F9CDDB6B4EED4FBD652D5B74B21102C515F37BE298F1A8426
)

FetchContent_Declare(
    glm
    URL https://github.com/g-truc/glm/archive/refs/tags/1.0.1.zip
    URL_HASH
        SHA256=09C5716296787E1F7FCB87B1CBDBF26814EC1288ED6259CCD30D5D9795809FA5
)

FetchContent_Declare(
    reproc
    URL https://github.com/DaanDeMeyer/reproc/archive/refs/tags/v14.2.5.zip
    URL_HASH
        SHA256=21B168C38ADB22F4B48391D8193DBC3927F1F2E678C2058D6944A29B64ACC6C9
)

add_subdirectory(glad)
add_subdirectory(GLFW)
add_subdirectory(ImGui)
add_subdirectory(KHR)
add_subdirectory(stb)
add_subdirectory(yaml-cpp)
add_subdirectory(dotnet-sdk)
add_subdirectory(zlib)
add_subdirectory(libzip)
add_subdirectory(glm)
add_subdirectory(reproc)
