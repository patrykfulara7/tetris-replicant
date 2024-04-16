#pragma once

#include "tetpch.hxx"

#include "Tetromino.hxx"

class Board
{
private:
    std::vector<std::vector<uint8_t>> board;

    uint16_t width;
    uint16_t height;
    
public:
    Board(uint16_t width, uint16_t height);

    void AddTetromino(const Tetromino& tetromino);
    void RemoveTetromino(const Tetromino& tetromino);
    bool DoesTetrominoFit(const Tetromino& tetromino);

    inline uint16_t GetWidth() const { return width; }
    inline uint16_t GetHeight() const { return height; }
    inline const std::vector<uint8_t> operator[] (std::size_t index) const { return board[index]; }
};
