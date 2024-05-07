add_subdirectory(glfw)
add_subdirectory(glm)
add_subdirectory(stb_image)

set(LIBS
    GL
    glfw
    GLEW
    glm
    stb_image
    CACHE INTERNAL ""
)
