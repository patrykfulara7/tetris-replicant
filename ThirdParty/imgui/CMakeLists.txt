project(imgui)

add_library(${PROJECT_NAME} STATIC
    imconfig.h
    imgui.cpp
    imgui.h
    imgui_draw.cpp
    imgui_internal.h
    imgui_tables.cpp
    imgui_widgets.cpp
    imstb_rectpack.h
    imstb_textedit.h
    imstb_truetype.h
    imgui_impl_opengl3.h
    imgui_impl_opengl3.cpp
    imgui_impl_opengl3_loader.h
    imgui_impl_glfw.h
    imgui_impl_glfw.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ../
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
    glfw
)