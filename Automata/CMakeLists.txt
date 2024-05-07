set(AUTOMATA_PRJ_NAME automata)

project(${AUTOMATA_PRJ_NAME})

add_library(${AUTOMATA_PRJ_NAME} "")
add_subdirectory(src)
target_include_directories(${AUTOMATA_PRJ_NAME} PRIVATE src)
target_link_libraries(${AUTOMATA_PRJ_NAME} PRIVATE ${LIBS})
