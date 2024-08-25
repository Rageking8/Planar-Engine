planar_message(STATUS "Fetching nativefiledialog-extended")

FetchContent_MakeAvailable(nativefiledialog-extended)

copy_single_source(
    ${nativefiledialog-extended_SOURCE_DIR}/src/include/nfd.h
    ${PLANAR_EXTERNAL_INCLUDE_DIR}
)
copy_third_party_include(nativefiledialog-extended src/include/)

set_property(TARGET nfd PROPERTY
    MSVC_RUNTIME_LIBRARY MultiThreaded$<$<CONFIG:Debug>:Debug>
)
