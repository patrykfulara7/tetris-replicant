#include "Tetromino.hxx"

Tetromino::Tetromino(uint8_t tetromino, uint8_t rotation, const glm::ivec2 &position)
    : tetromino(tetromino), rotation(rotation), position(position) {
}
