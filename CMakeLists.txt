cmake_minimum_required(VERSION 3.13..3.29 FATAL_ERROR)

project("Planar Engine" VERSION 0.1.0 LANGUAGES CXX)

add_executable(PlanarEngine)

set(PLANAR_FETCHED_INCLUDES_DIR "${CMAKE_BINARY_DIR}/Fetched/Includes")

add_subdirectory(Planar/Source)
add_subdirectory(ThirdParty)

target_link_libraries(PlanarEngine PRIVATE GLFW)
target_include_directories(PlanarEngine PRIVATE
	${PLANAR_FETCHED_INCLUDES_DIR})
