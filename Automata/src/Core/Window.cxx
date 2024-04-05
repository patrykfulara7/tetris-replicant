#include "Core/Window.hxx"
#include "Core/Core.hxx"

namespace Automata
{
    static void DebugMessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam)
    {
        (void)source, (void)type, (void)id, (void)severity, (void)length, (void)userParam;

        std::cerr << message << std::endl;
        abort();
    }

    Window::Window(int width, int height, const std::string& title)
        : width(width), height(height), title(title)
    {
        AM_ASSERT(glfwInit() == GLFW_TRUE);

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);

        windowHandle = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        
        AM_ASSERT(windowHandle != nullptr);

        glfwMakeContextCurrent(windowHandle);

        AM_ASSERT(glewInit() == GL_FALSE);

        std::cout << glGetString(GL_VERSION) << std::endl;

        glEnable(GL_DEBUG_CALLBACK_FUNCTION);
        glDebugMessageCallback(DebugMessageCallback, nullptr);
    }

    Window::~Window()
    {
        glfwDestroyWindow(windowHandle);
        glfwTerminate();
    }

    void Window::Update()
    {
        glfwPollEvents();
        glfwSwapBuffers(windowHandle);
    }
}
