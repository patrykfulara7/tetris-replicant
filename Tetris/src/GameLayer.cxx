#include "GameLayer.hxx"
#include "GameOverState.cxx"
#include "GameState.hxx"
#include "StateIdentifiers.hxx"

GameLayer::GameLayer() {
}

void GameLayer::OnAttach() {
    stateManager.RegisterState<GameState>(StateID::Game);
    stateManager.RegisterState<GameOverState>(StateID::GameOver);
    stateManager.PushState(StateID::Game);
}

void GameLayer::OnDetach() {
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
