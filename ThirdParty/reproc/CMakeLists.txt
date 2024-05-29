message(STATUS "Fetching reproc")

set(REPROC++ ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(reproc)

copy_single_source(
    ${reproc_SOURCE_DIR}/reproc++/include/reproc++
    ${PLANAR_EXTERNAL_INCLUDE_DIR}
)
copy_single_source(
    ${reproc_SOURCE_DIR}/reproc++/include/reproc++/
    ${PLANAR_EXTERNAL_THIRD_PARTY_INCLUDE_DIR}/reproc
)
