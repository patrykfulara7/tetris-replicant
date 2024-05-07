cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

project(Tetris)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Automata)
add_subdirectory(Tetris)
add_subdirectory(ThirdParty)
