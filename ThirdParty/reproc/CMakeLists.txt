planar_message(STATUS "Fetching reproc")

set(REPROC++ ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(reproc)

copy_single_source(
    ${reproc_SOURCE_DIR}/reproc++/include/reproc++
    ${PLANAR_EXTERNAL_INCLUDE_DIR}
)
copy_third_party_include(reproc reproc++/include/reproc++/)

set_property(TARGET reproc PROPERTY
    MSVC_RUNTIME_LIBRARY MultiThreaded$<$<CONFIG:Debug>:Debug>
)

set_property(TARGET reproc++ PROPERTY
    MSVC_RUNTIME_LIBRARY MultiThreaded$<$<CONFIG:Debug>:Debug>
)
