add_subdirectory(glad)
add_subdirectory(glfw)
add_subdirectory(glm)
add_subdirectory(stb_image)

set(LIBS
    glad
    glfw
    glm
    stb_image
    CACHE INTERNAL ""
)
