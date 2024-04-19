cmake_minimum_required(VERSION 3.13..3.29 FATAL_ERROR)

project("Planar Engine" VERSION 0.1.0 LANGUAGES CXX)

add_executable(PlanarEngine)

add_subdirectory(Planar/Source)
