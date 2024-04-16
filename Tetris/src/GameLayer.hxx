#pragma once

#include "tetpch.hxx"

#include "Tetromino.hxx"
#include "Board.hxx"

class GameLayer : public Automata::Layer
{
private:
    static constexpr glm::ivec2 INITIAL_POSITION = glm::ivec2(3, 0);

    Tetromino tetromino;
    Board board;

    std::array<std::shared_ptr<Automata::Texture>, 8> blockTextures;

    enum class Action
    {
        None = 0,
        MoveDown, MoveLeft, MoveRight,
        RotateLeft, RotateRight
    };

    Action nextAction = Action::None;

public:
    GameLayer();
    ~GameLayer() override = default;

    void OnAttach() override;
    void OnDetach() override;
    void OnEvent(Automata::Event& event) override;
    void OnUpdate(double deltaTime) override;
    void OnRender() override;
};
