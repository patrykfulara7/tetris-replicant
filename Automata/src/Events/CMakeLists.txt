file(GLOB EVENTS_SRCS *.cxx *.hxx)

target_sources(${AUTOMATA_PRJ_NAME} PRIVATE ${EVENTS_SRCS})
