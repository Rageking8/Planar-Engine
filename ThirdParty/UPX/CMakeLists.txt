message(STATUS "Fetching UPX")

FetchContent_MakeAvailable(upx)

file(COPY ${upx_SOURCE_DIR}/upx.exe DESTINATION
    ${CMAKE_BINARY_DIR}/Asset
)
