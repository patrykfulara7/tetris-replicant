#pragma once

#include "tetpch.hxx"

#include "Board.hxx"
#include "State.hxx"

class GameOverState : public State {
  private:
    static constexpr u_int16_t TILE_SIZE = 32;

    Board board;
    Automata::Texture blockTexture;

  public:
    explicit GameOverState(StateManager &stateManager);
    ~GameOverState() override;

    void OnEvent(Automata::Event &event) override;
    void OnUpdate(double deltaTime) override;
    void OnRender() override;
};
