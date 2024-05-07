set(LIBS_DIR ThirdParty)

# glm
add_subdirectory(glm)
set_target_properties(
    glm
    PROPERTIES FOLDER ${LIBS_DIR}
)

# stb_image
add_subdirectory(stb_image)
set_target_properties(
    stb_image
    PROPERTIES FOLDER ${LIBS_DIR}
)

set(LIBS
    GL
    glfw
    GLEW
    glm
    stb_image
    CACHE INTERNAL ""
)
