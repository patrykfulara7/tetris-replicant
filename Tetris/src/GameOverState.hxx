#pragma once

#include "tetpch.hxx"

#include "Board.hxx"
#include "Cache.hxx"
#include "State.hxx"

class GameOverState : public State {
  private:
    std::shared_ptr<Cache> cache = nullptr;

  public:
    explicit GameOverState(StateManager &stateManager);
    ~GameOverState() override;

    void OnEvent(Automata::Event &event) override;
    void OnUpdate(double deltaTime) override;
    void OnRender() override;
};
