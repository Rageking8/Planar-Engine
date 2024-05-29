message(STATUS "Fetching LZMA SDK")

FetchContent_MakeAvailable(lzma-sdk)

file(COPY ${lzma-sdk_SOURCE_DIR}/bin/7zr.exe DESTINATION
    ${CMAKE_BINARY_DIR}/Asset
)
