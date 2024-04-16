#pragma once

#include "ampch.hxx"

#include "Core/Window.hxx"
#include "Core/Layer.hxx"

#include "Events/Event.hxx"

namespace Automata
{
    class Application
    {
    private:
        static Application *instance;

        std::unique_ptr<Window> window = nullptr;
        std::unique_ptr<Layer> layer = nullptr;

        bool isRunning = true;

    public:
        Application(int width, int height, const std::string& title);
        virtual ~Application();

        void PushLayer(Layer *layer);
        void OnEvent(Event& event);

        void Run();
        static void Close();

        static inline Application& Get() { return *instance; }
        inline Window& GetWindow() { return *window; }
    };

    Application* CreateApplication();
}
