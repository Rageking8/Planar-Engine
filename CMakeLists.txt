cmake_minimum_required(VERSION 3.13..3.29 FATAL_ERROR)

project("Planar Engine" VERSION 0.1.0 LANGUAGES CXX)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

add_executable(PlanarEngine)

set(PLANAR_FETCHED_INCLUDES_DIR
	"${CMAKE_BINARY_DIR}/Fetched/Includes")

add_subdirectory(Planar/Source)
add_subdirectory(ThirdParty)

target_link_libraries(PlanarEngine PRIVATE glfw)
target_include_directories(PlanarEngine PRIVATE
	${PLANAR_FETCHED_INCLUDES_DIR})

add_custom_command(TARGET PlanarEngine POST_BUILD COMMAND
	${CMAKE_COMMAND} -E copy $<TARGET_FILE:PlanarEngine>
	$<TARGET_RUNTIME_DLLS:PlanarEngine>
	$<TARGET_FILE_DIR:PlanarEngine> COMMAND_EXPAND_LISTS)
