#pragma once

#include "tetpch.hxx"

#include "State.hxx"

class StateManager
{
private:
    std::unique_ptr<State> state = nullptr;
    std::unordered_map<StateID, std::function<std::unique_ptr<State>()>> stateConstructors;

public:
    template <typename T>
    void RegisterState(StateID state);
    void PushState(StateID state);
    void PopState();

    void OnEvent(Automata::Event& event);
    void OnUpdate(double deltaTime);
    void OnRender();
};

template <typename T>
void StateManager::RegisterState(StateID state)
{
    stateConstructors[state] = [this]()
    {
        return std::unique_ptr<State>(new T(*this));
    };
}
