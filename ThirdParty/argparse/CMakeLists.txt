planar_message(STATUS "Fetching argparse")

FetchContent_MakeAvailable(argparse)

copy_single_source(
    ${argparse_SOURCE_DIR}/include/argparse/argparse.hpp
    ${PLANAR_EXTERNAL_THIRD_PARTY_INCLUDE_DIR}/argparse
)

set_property(TARGET argparse PROPERTY
    MSVC_RUNTIME_LIBRARY MultiThreaded$<$<CONFIG:Debug>:Debug>
)
