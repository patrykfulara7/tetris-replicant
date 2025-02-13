#include "GameContext.hxx"
#include "GameLayer.hxx"
#include "GameOverState.hxx"
#include "GameState.hxx"
#include "StateIdentifiers.hxx"

void GameLayer::OnAttach() {
    stateManager.RegisterState<GameState>(StateID::Game);
    stateManager.RegisterState<GameOverState>(StateID::GameOver);

    stateManager.PushState(StateID::Game, nullptr);
}

void GameLayer::OnDetach() {
    stateManager.PopState();
}

void GameLayer::OnEvent(Automata::Event &event) {
    stateManager.OnEvent(event);
}

void GameLayer::OnUpdate(double deltaTime) {
    stateManager.OnUpdate(deltaTime);
}

void GameLayer::OnRender() {
    stateManager.OnRender();
}
