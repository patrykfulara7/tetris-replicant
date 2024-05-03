#include "State.hxx"
#include "StateManager.hxx"

State::State(StateManager &stateManager) : stateManager(&stateManager) {
}

void State::PushState(StateID stateID) {
    stateManager->PushState(stateID);
}

void State::PopState() {
    stateManager->PopState();
}
