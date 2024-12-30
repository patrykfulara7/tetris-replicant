#pragma once

#include "tetpch.hxx"

#include "Board.hxx"
#include "Cache.hxx"
#include "Sequence.hxx"
#include "State.hxx"
#include "Tetromino.hxx"

class GameState : public State {
    static constexpr glm::ivec2 INITIAL_POSITION = glm::ivec2(3, 0);
    static constexpr u_int16_t TILE_SIZE = 32;

    std::shared_ptr<Cache> cache = nullptr;

    Tetromino tetromino;
    Sequence sequence;

    std::vector<Automata::Texture> blockTextures;

    std::thread fall;

    enum class Action {
        None,
        MoveDown,
        MoveLeft,
        MoveRight,
        RotateLeft,
        RotateRight
    };

    Action nextAction = Action::None;

  private:
    void Fall();

  public:
    explicit GameState(StateManager &stateManager);
    ~GameState() override;

    void OnEvent(Automata::Event &event) override;
    void OnUpdate(double deltaTime) override;
    void OnRender() override;
};
