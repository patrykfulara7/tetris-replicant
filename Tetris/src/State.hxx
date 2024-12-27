#pragma once

#include "tetpch.hxx"

#include "StateIdentifiers.hxx"

class StateManager;

class State {
  private:
    StateManager *stateManager = nullptr;

  protected:
    void PushState(StateID stateID);
    void PopState();

    void SetUserPointer(const std::shared_ptr<void> &userPointer);
    std::shared_ptr<void> GetUserPointer();

  public:
    State(StateManager &stateManager);
    virtual ~State() = default;

    virtual void OnEvent(Automata::Event &event) = 0;
    virtual void OnUpdate(double deltaTime) = 0;
    virtual void OnRender() = 0;
};
