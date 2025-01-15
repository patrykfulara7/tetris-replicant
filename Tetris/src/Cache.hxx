#pragma once

#include "Board.hxx"
#include "tetpch.hxx"

struct Cache {
  public:
    static constexpr uint16_t TILE_SIZE = 32;

    Board board;
    std::vector<Automata::Texture> blockTextures;

  public:
    explicit Cache(const Board &board) : board(board) {
    }

    static inline std::shared_ptr<Cache> Create(Board board) {
        return std::make_shared<Cache>(board);
    }
};
