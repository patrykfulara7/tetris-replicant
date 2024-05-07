add_subdirectory(Core)
add_subdirectory(Events)
add_subdirectory(Graphics)
add_subdirectory(Utils)

target_precompile_headers(${AUTOMATA_PRJ_NAME} PRIVATE ampch.hxx)
