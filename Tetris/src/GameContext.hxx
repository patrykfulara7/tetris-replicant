#pragma once

#include "tetpch.hxx"

#include "Board.hxx"

struct GameContext {
  public:
    static constexpr uint16_t TILE_SIZE = 32;

    Board board;
    std::vector<Automata::Texture> blockTextures;

  public:
    explicit GameContext(const Board &board) : board(board) {
    }
};
