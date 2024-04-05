#pragma once

#include "ampch.hxx"

namespace Automata
{
    class Window
    {
    private:
        GLFWwindow *windowHandle = nullptr;

        int width = 0;
        int height = 0;
        std::string title;

    public:
        Window(int width, int height, const std::string& title);
        ~Window();

        void Update();

        inline GLFWwindow* GetWindowHandle() { return windowHandle; }
        static inline std::unique_ptr<Window> Create(int width, int height, const std::string& title)
        {
            return std::make_unique<Window>(width, height, title);
        }
    };
}
