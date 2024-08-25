planar_message(STATUS "Fetching argparse")

FetchContent_MakeAvailable(argparse)

copy_third_party_include(argparse include/argparse/argparse.hpp)

set_property(TARGET argparse PROPERTY
    MSVC_RUNTIME_LIBRARY MultiThreaded$<$<CONFIG:Debug>:Debug>
)
