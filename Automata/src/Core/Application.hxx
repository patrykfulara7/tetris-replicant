#pragma once

#include "ampch.hxx"

#include "Core/Core.hxx"
#include "Core/Layer.hxx"
#include "Core/Window.hxx"

#include "Events/Event.hxx"

namespace Automata {
    class Application {
      private:
        static Application *instance;

        Window window;
        std::unique_ptr<Layer> layer = nullptr;
        bool isRunning = true;

      public:
        Application(int width, int height, const std::string &title);
        virtual ~Application();

        void PushLayer(Layer *layer);
        void OnEvent(Event &event);

        static void Close();
        void Run();

        static inline Application &Get() {
            AM_ASSERT(instance != nullptr);

            return *instance;
        }

        static inline Window &GetWindow() {
            AM_ASSERT(instance != nullptr);

            return Application::Get().window;
        }
    };

    Application *CreateApplication();
} // namespace Automata
