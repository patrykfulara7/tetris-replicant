#pragma once

#include "tetpch.hxx"

#include "Board.hxx"
#include "Sequence.hxx"
#include "State.hxx"
#include "Tetromino.hxx"

class GameState : public State
{
    static constexpr glm::ivec2 INITIAL_POSITION = glm::ivec2(3, 0);

    Tetromino tetromino;
    Board board;
    Sequence sequence;

    std::vector<Automata::Texture> blockTextures;

    std::thread fall;

    enum class Action
    {
        None = 0,
        MoveDown, MoveLeft, MoveRight,
        RotateLeft, RotateRight
    };

    Action nextAction = Action::None;

private:
    void Fall();

public:
    GameState(StateManager& stateManager);
    ~GameState();

    void OnEvent(Automata::Event& event) override;
    void OnUpdate(double deltaTime) override;
    void OnRender() override;
};
