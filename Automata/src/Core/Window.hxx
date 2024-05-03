#pragma once

#include "ampch.hxx"

#include "Events/Event.hxx"

namespace Automata {
    class Window {
      private:
        using EventCallback = std::function<void(Event &)>;

        struct WindowData {
            GLFWwindow *windowHandle = nullptr;
            EventCallback callback;

            int width = 0;
            int height = 0;
            std::string title;

            WindowData(int width, int height, const std::string &title) : width(width), height(height), title(title) {
            }
        };

        WindowData data;

      public:
        Window(int width, int height, const std::string &title);
        ~Window();

        void Update();

        inline void SetEventCallback(const EventCallback &callback) {
            data.callback = callback;
        }

        inline GLFWwindow *GetWindowHandle() const {
            return data.windowHandle;
        }
        static inline std::unique_ptr<Window> Create(int width, int height, const std::string &title) {
            return std::make_unique<Window>(width, height, title);
        }
    };
} // namespace Automata
