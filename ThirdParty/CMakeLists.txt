include(FileUtils)
include(ThirdPartyUtils)

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
    URL https://github.com/ocornut/imgui/archive/refs/tags/v1.91.0-docking.zip
    URL_HASH
        SHA256=657B225D99FD34CE10A3BD0DA2A72359362AE709A774811AA22EE30085660240
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

FetchContent_Declare(
    lzma-sdk
    URL https://7-zip.org/a/lzma2406.7z
    URL_HASH
        SHA256=F32FD1C4012E25F961F6E18A31C279D517C14490F1B0E08B05B70E8463ECF937
)

FetchContent_Declare(
    upx
    URL https://github.com/upx/upx/releases/download/v4.2.4/upx-4.2.4-win64.zip
    URL_HASH
        SHA256=22E9EF20E4C72AAD85E32C71CBC9C086436C179456382AA75C0C24868456A671
)

FetchContent_Declare(
    nativefiledialog-extended
    URL https://github.com/btzy/nativefiledialog-extended/archive/refs/tags/v1.2.0.zip
    URL_HASH
        SHA256=27DC13320816392D0D9905C60645AA684784C7C2559D656B504021EDD40F07ED
)

FetchContent_Declare(
    soloud
    URL https://github.com/jarikomppa/soloud/archive/799c535efcf47bb2b440f809b21b4d72e2a8b4b0.zip
    URL_HASH
        SHA256=8C53CE9EFB250024BA977384ADEEC500A39D702A338F8B3328A73B1342259731
)

FetchContent_Declare(
    argparse
    URL https://github.com/p-ranav/argparse/archive/refs/tags/v3.1.zip
    URL_HASH
        SHA256=3E5A59AB7688DCD1F918BC92051A10564113D4F36C3BBED3EF596C25E519A062
)

add_subdirectory(glad)
add_subdirectory(GLFW)
add_subdirectory(ImGui)
add_subdirectory(KHR)
add_subdirectory(stb)
add_subdirectory(yaml-cpp)
add_subdirectory(dotnet-sdk)
add_subdirectory(glm)
add_subdirectory(reproc)
add_subdirectory(lzma-sdk)
add_subdirectory(UPX)
add_subdirectory(nativefiledialog-extended)
add_subdirectory(SoLoud)
add_subdirectory(argparse)
