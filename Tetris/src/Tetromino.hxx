#pragma once

#include "tetpch.hxx"

class Tetromino {
  private:
    static constexpr std::array<std::array<uint8_t, 4>, 7> TETROMINOE_SHAPES = { {
        { 4, 5, 6, 7 },  // I
        { 5, 6, 9, 10 }, // O
        { 5, 8, 9, 10 }, // T
        { 5, 6, 8, 9 },  // S
        { 4, 5, 9, 10 }, // Z
        { 4, 8, 9, 10 }, // J
        { 6, 8, 9, 10 }  // L
    } };

  public:
    uint8_t tetromino = 0;
    uint8_t rotation = 0;
    glm::ivec2 position = { 0, 0 };

  public:
    Tetromino(uint8_t tetromino, uint8_t rotation, const glm::ivec2 &position);

    inline uint8_t operator[](size_t index) const {
        return TETROMINOE_SHAPES[tetromino][index];
    }
};
