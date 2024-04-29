#include "StateManager.hxx"

void StateManager::PushState(StateID stateID)
{
    auto stateConstructor = stateConstructors.find(stateID);
    assert(stateConstructor != stateConstructors.end());
    state = stateConstructor->second();
}

void StateManager::PopState()
{
    state.release();
}

void StateManager::OnEvent(Automata::Event& event)
{
    state->OnEvent(event);
}

void StateManager::OnUpdate(double deltaTime)
{
    state->OnUpdate(deltaTime);
}

void StateManager::OnRender()
{
    state->OnRender();
}
