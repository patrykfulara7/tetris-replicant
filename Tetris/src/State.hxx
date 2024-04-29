#pragma once

#include "tetpch.hxx"

#include "StateIdentifiers.hxx"

class StateManager;

class State
{
private:
    StateManager *stateManager = nullptr;

protected:
    void PushState(StateID stateID);
    void PopState();

public:
    State(StateManager& stateManager);
    virtual ~State() = default;

    virtual void OnEvent(Automata::Event& event) = 0; 
    virtual void OnUpdate(double deltaTime) = 0;
    virtual void OnRender() = 0;
};
