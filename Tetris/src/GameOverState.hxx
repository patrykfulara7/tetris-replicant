#pragma once

#include "tetpch.hxx"

#include "Board.hxx"
#include "GameContext.hxx"
#include "State.hxx"

class GameOverState : public State {
  public:
    GameOverState(StateManager &stateManager, std::shared_ptr<GameContext> gameContext);
    ~GameOverState() override;

    void OnEvent(Automata::Event &event) override;
    void OnUpdate(double deltaTime) override;
    void OnRender() override;
};
