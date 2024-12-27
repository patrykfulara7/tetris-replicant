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

void State::SetUserPointer(const std::shared_ptr<void> &userPointer) {
    stateManager->SetUserPointer(userPointer);
}

std::shared_ptr<void> State::GetUserPointer() {
    return stateManager->GetUserPointer();
}
