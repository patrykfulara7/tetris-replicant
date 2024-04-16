cmake_minimum_required(VERSION 3.22.1)

project(Tetris)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

file(GLOB_RECURSE SOURCE *.cxx *.hxx)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ..)

add_executable(a.out ${SOURCE})

target_precompile_headers(a.out PRIVATE Automata/src/ampch.hxx Tetris/src/tetpch.hxx)
target_compile_options(a.out PRIVATE -DAM_DEBUG -Wall -Wextra)
target_include_directories(a.out PRIVATE Automata/src Automata/vendor Tetris/src)
target_link_libraries(a.out GL GLEW glfw)
