cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

project(tetris)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

file(GLOB_RECURSE SOURCE *.cxx *.hxx)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ..)

add_executable(${PROJECT_NAME} ${SOURCE})

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 23
)

target_precompile_headers(${PROJECT_NAME} PRIVATE
    Automata/src/ampch.hxx
    Tetris/src/tetpch.hxx
)

target_include_directories(${PROJECT_NAME} PRIVATE
    Automata/src
    Automata/vendor
    Tetris/src
)

target_link_libraries(${PROJECT_NAME} GL GLEW glfw)
