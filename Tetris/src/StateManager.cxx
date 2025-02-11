#include "StateManager.hxx"

void StateManager::PushState(StateID stateID, const std::shared_ptr<GameContext> &gameContext) {
    auto stateConstructor = stateConstructors.find(stateID);
    assert(stateConstructor != stateConstructors.end());
    state = stateConstructor->second(gameContext);
}

void StateManager::PopState() {
    state.release();
}

void StateManager::OnEvent(Automata::Event &event) {
    state->OnEvent(event);
}

void StateManager::OnUpdate(double deltaTime) {
    state->OnUpdate(deltaTime);
}

void StateManager::OnRender() {
    state->OnRender();
}
