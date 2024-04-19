#include "Core/Window.hxx"
#include "Core/Core.hxx"
#include "Core/Input.hxx"

#include "Events/KeyboardEvent.hxx"

namespace Automata
{
    Window::Window(int width, int height, const std::string& title)
        : data(width, height, title)
    {
        AM_ASSERT(glfwInit() == GLFW_TRUE);

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);

        data.windowHandle = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        
        AM_ASSERT(data.windowHandle != nullptr);

        glfwMakeContextCurrent(data.windowHandle);
        glfwSwapInterval(1);

        AM_ASSERT(glewInit() == GL_FALSE);
        std::cout << glGetString(GL_VERSION) << std::endl;

        glEnable(GL_DEBUG_CALLBACK_FUNCTION);
        glDebugMessageCallback([](GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam)
        {
            (void)source, (void)type, (void)id, (void)severity, (void)length, (void)userParam;

            std::cerr << message << std::endl;
            abort();
        },
        nullptr);

        glfwSetWindowUserPointer(data.windowHandle, &data);

        glfwSetKeyCallback(data.windowHandle, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            (void)scancode, (void)mods;

            auto data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));

            switch (action)
            {
                case GLFW_PRESS:
                case GLFW_REPEAT:
                {
                    KeyPressedEvent event(key);
                    data->callback(event);
                }
                break;

                case GLFW_RELEASE:
                {
                    KeyReleasedEvent event(key);
                    data->callback(event);
                }
                break;
            }
        });
    }

    Window::~Window()
    {
        glfwDestroyWindow(data.windowHandle);
        glfwTerminate();
    }

    void Window::Update()
    {
        glfwPollEvents();
        glfwSwapBuffers(data.windowHandle);
    }
}
