#pragma once

#include "tetpch.hxx"

#include "GameContext.hxx"
#include "State.hxx"

class StateManager {
  private:
    std::unique_ptr<State> state = nullptr;
    std::unordered_map<StateID, std::function<std::unique_ptr<State>(std::shared_ptr<GameContext>)>> stateConstructors;

  public:
    template <typename T>
    void RegisterState(StateID state);
    void PushState(StateID state, const std::shared_ptr<GameContext> &gameContext);
    void PopState();

    void OnEvent(Automata::Event &event);
    void OnUpdate(double deltaTime);
    void OnRender();
};

template <typename T>
void StateManager::RegisterState(StateID state) {
    stateConstructors[state] = [this](std::shared_ptr<GameContext> gameContext) {
        return std::unique_ptr<State>(new T(*this, gameContext));
    };
}
