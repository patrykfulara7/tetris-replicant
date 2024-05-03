#include "Core/Input.hxx"
#include "Core/Application.hxx"

namespace Automata {
    bool Input::IsKeyPressed(Key key) {
        auto windowHandle = Application::GetWindow().GetWindowHandle();
        auto state = glfwGetKey(windowHandle, static_cast<int>(key));
        return state == GLFW_PRESS or state == GLFW_REPEAT;
    }
} // namespace Automata
