#include "Core/Core.hxx"
#include "Core/Application.hxx"

#include "Graphics/Renderer.hxx"

namespace Automata
{
    Application* Application::instance = nullptr;

    Application::Application(int width, int height, const std::string& title)
    {
        AM_ASSERT(instance == nullptr);
        instance = this;

        window = Window::Create(width, height, title);

        window->SetEventCallback(AM_BIND_EVENT(Application::OnEvent));

        Renderer::Init(width, height);
    }

    Application::~Application()
    {
        layer->OnDetach();
    }

    void Application::PushLayer(Layer *layer)
    {
        this->layer = std::unique_ptr<Layer>(layer);
        this->layer->OnAttach();
    }

    void Application::OnEvent(Event& event)
    {
        layer->OnEvent(event);
    }

    void Application::Close()
    {
        if (instance != nullptr)
            Application::Get().isRunning = false;
    }

    void Application::Run()
    {
        double previousTime = 0.0;
        while (isRunning)
        {
            double time = glfwGetTime();
            double deltaTime = time - previousTime;
            
            layer->OnUpdate(deltaTime);

            Renderer::Clear();

            layer->OnRender();

            window->Update();
        }
    }
}