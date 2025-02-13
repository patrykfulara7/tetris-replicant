#include "Core/Application.hxx"
#include "Core/Core.hxx"

#include "Graphics/Renderer.hxx"

namespace Automata {
    Application *Application::instance = nullptr;

    Application::Application(int width, int height, const std::string &title) : window(width, height, title) {
        AM_ASSERT(instance == nullptr);
        instance = this;

        window.SetEventCallback(AM_BIND_EVENT(Application::OnEvent));

        Renderer::Init(width, height);
    }

    Application::~Application() {
        for (auto &layer : layers) {
            layer->OnDetach();
        }
    }

    void Application::PushLayer(std::unique_ptr<Layer> layer) {
        layers.emplace_back(std::move(layer));
        layers.back()->OnAttach();
    }

    void Application::OnEvent(Event &event) {
        for (auto &layer : layers) {
            layer->OnEvent(event);
        }
    }

    void Application::Close() {
        AM_ASSERT(instance != nullptr);

        Application::Get().isRunning = false;
    }

    void Application::Run() {
        double previousTime = 0.0;
        while (isRunning) {
            double time = glfwGetTime();
            double deltaTime = time - previousTime;

            for (auto &layer : layers) {
                layer->OnUpdate(deltaTime);
            }

            Renderer::Clear();

            for (auto &layer : layers) {
                layer->OnRender();
            }

            window.Update();
        }
    }
} // namespace Automata
