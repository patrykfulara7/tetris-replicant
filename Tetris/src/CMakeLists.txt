file(GLOB TETRIS_SRCS *.cxx *.hxx)

target_sources(${TETRIS_PRJ_NAME} PRIVATE ${TETRIS_SRCS})
target_precompile_headers(${TETRIS_PRJ_NAME} PRIVATE tetpch.hxx)
