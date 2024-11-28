add_subdirectory(glad)
add_subdirectory(glfw)
add_subdirectory(glm)
add_subdirectory(stb_image)

set(THIRD_PARTY_LIBRARIES
    glad
    glfw
    glm
    stb_image
    CACHE INTERNAL ""
)
