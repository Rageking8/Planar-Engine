planar_message(STATUS "Fetching nativefiledialog-extended")

FetchContent_MakeAvailable(nativefiledialog-extended)

copy_single_source(
    ${nativefiledialog-extended_SOURCE_DIR}/src/include/nfd.h
    ${PLANAR_EXTERNAL_INCLUDE_DIR}
)
copy_single_source(
    ${nativefiledialog-extended_SOURCE_DIR}/src/include/
    ${PLANAR_EXTERNAL_THIRD_PARTY_INCLUDE_DIR}/nativefiledialog-extended
)

set_property(TARGET nfd PROPERTY
    MSVC_RUNTIME_LIBRARY MultiThreaded$<$<CONFIG:Debug>:Debug>
)
