#pragma once

#include "ampch.hxx"

namespace Automata {
    using KeyCode = uint8_t;

    enum Key : KeyCode {
        C = GLFW_KEY_C,
        J = GLFW_KEY_J,
        H = GLFW_KEY_H,
        L = GLFW_KEY_L,
        Q = GLFW_KEY_Q,
        E = GLFW_KEY_E
    };
} // namespace Automata
