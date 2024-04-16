#pragma once

#include "tetpch.hxx"

class Tetromino
{
private:
    static constexpr std::array<std::array<uint8_t, 4>, 7> tetrominoes =
    {{
        //  0  1  2  3
        //  4  5  6  7
        //  8  9 10 11
        // 12 13 14 15

        {  8,  9, 10, 11 }, // I
        {  5,  6,  9, 10 }, // O
        {  5,  8,  9, 10 }, // T
        {  5,  6,  8,  9 }, // S
        {  4,  5,  9, 10 }, // Z
        {  4,  8,  9, 10 }, // J
        {  6,  8,  9, 10 }  // L
    }};

    uint8_t tetromino = 0;
    uint8_t rotation = 0;
    glm::ivec2 position = { 0, 0 };
    
public:
    Tetromino(uint8_t tetromino, uint8_t rotation, const glm::ivec2& position);

    void SetTetromino(uint8_t tetromino);
    void SetRotation(uint8_t rotation);
    void SetPosition(const glm::vec2& position);

    inline uint8_t GetTetromino() const { return tetromino; }
    inline uint8_t GetRotation() const { return rotation; }
    inline const glm::ivec2& GetPosition() const { return position; }

    inline uint8_t operator[](size_t index) const { return tetrominoes[tetromino][index]; }
};
