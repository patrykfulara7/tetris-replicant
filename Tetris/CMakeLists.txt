set(TETRIS_PRJ_NAME tetris)
project(${TETRIS_PRJ_NAME})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../..)

add_executable(${TETRIS_PRJ_NAME} )
add_subdirectory(src)
target_include_directories(${TETRIS_PRJ_NAME} PRIVATE src)
target_link_libraries(${TETRIS_PRJ_NAME} PRIVATE automata)
