#include "GameLayer.hxx"
#include "StateIdentifiers.hxx"
#include "GameState.hxx"

GameLayer::GameLayer()
{
}

void GameLayer::OnAttach()
{
    stateManager.RegisterState<GameState>(StateID::GAME);
    stateManager.PushState(StateID::GAME);
}

void GameLayer::OnDetach()
{
}

void GameLayer::OnEvent(Automata::Event& event)
{
    stateManager.OnEvent(event);
}

void GameLayer::OnUpdate(double deltaTime)
{
    stateManager.OnUpdate(deltaTime);
}

void GameLayer::OnRender()
{
    stateManager.OnRender();
}
