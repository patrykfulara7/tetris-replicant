#include "State.hxx"
#include "StateManager.hxx"

State::State(StateManager &stateManager, const std::shared_ptr<GameContext> &gameContext)
    : stateManager(&stateManager), gameContext(gameContext) {
}

void State::PushState(StateID stateID, const std::shared_ptr<GameContext> &gameContext) {
    stateManager->PushState(stateID, gameContext);
}

void State::PopState() {
    stateManager->PopState();
}
