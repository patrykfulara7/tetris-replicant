#pragma once

#include "tetpch.hxx"

#include "GameContext.hxx"
#include "StateIdentifiers.hxx"

class StateManager;

class State {
  private:
    StateManager *stateManager = nullptr;

  protected:
    std::shared_ptr<GameContext> gameContext = nullptr;

  protected:
    void PushState(StateID stateID, const std::shared_ptr<GameContext> &gameContext);
    void PopState();

  public:
    State(StateManager &stateManager, const std::shared_ptr<GameContext> &gameContext);
    virtual ~State() = default;

    virtual void OnEvent(Automata::Event &event) = 0;
    virtual void OnUpdate(double deltaTime) = 0;
    virtual void OnRender() = 0;
};
