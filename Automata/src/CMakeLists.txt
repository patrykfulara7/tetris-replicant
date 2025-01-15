add_subdirectory(Core)
add_subdirectory(Events)
add_subdirectory(Graphics)
add_subdirectory(Utils)

configure_file(CMakePlaceholders.hxx.in ${CMAKE_CURRENT_LIST_DIR}/CMakePlaceholders.hxx)

target_precompile_headers(${PROJECT_NAME}
    PRIVATE
    ampch.hxx
)