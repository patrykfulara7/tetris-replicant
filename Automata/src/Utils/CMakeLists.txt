file(GLOB UTILS_SRCS *.cxx *.hxx)

target_sources(${AUTOMATA_PRJ_NAME} PRIVATE ${UTILS_SRCS})
