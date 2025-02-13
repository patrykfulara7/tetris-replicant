add_subdirectory(glad)
add_subdirectory(glfw)
add_subdirectory(glm)
add_subdirectory(imgui)
add_subdirectory(stb_image)

set(THIRD_PARTY_LIBRARIES
    glad
    glfw
    glm
    imgui
    stb_image
    CACHE INTERNAL ""
)
