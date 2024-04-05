#include "GameLayer.hxx"

void GameLayer::OnAttach()
{
}

void GameLayer::OnDetach()
{
}

void GameLayer::OnUpdate(double deltaTime)
{
    (void)deltaTime;

    if (Automata::Input::IsKeyPressed(Automata::Key::C))
        Automata::Application::Get().Close();
}

void GameLayer::OnRender()
{
}
