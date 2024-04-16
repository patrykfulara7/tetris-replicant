#include "Tetromino.hxx"

Tetromino::Tetromino(uint8_t tetromino, uint8_t rotation, const glm::ivec2& position)
    : tetromino(tetromino), rotation(rotation), position(position)
{
}

void Tetromino::SetTetromino(uint8_t tetromino)
{
    this->tetromino = tetromino;
}

void Tetromino::SetRotation(uint8_t rotation)
{
    this->rotation = rotation;
}

void Tetromino::SetPosition(const glm::vec2& position)
{
    this->position = position;
}
