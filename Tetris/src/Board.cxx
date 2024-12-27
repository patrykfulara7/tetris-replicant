#include "Board.hxx"

Board::Board(uint16_t width, uint16_t height) : width(width), height(height) {
    board.resize(height);
    for (auto &row : board) {
        row.resize(width);
        std::fill(row.begin(), row.end(), 0);
    }
}

int Board::Rotate(uint8_t x, uint8_t rotation) {
    switch (rotation) {
        case 0: {
            return x;
        }
        case 1: {
            return (3 + 4 * x) % 17;
        }
        case 2: {
            return 15 - x;
        }
        case 3: {
            return 15 - (3 + 4 * x) % 17;
        }
    }

    return -1;
}

void Board::AddTetromino(const Tetromino &tetromino) {
    for (uint8_t i = 0; i < 4; i++) {
        uint8_t offset = Rotate(tetromino[i], tetromino.GetRotation());
        uint8_t x = tetromino.GetPosition().x + offset % 4;
        uint8_t y = tetromino.GetPosition().y + offset / 4;

        board[y][x] = tetromino.GetTetromino() + 1;
    }
}

void Board::RemoveTetromino(const Tetromino &tetromino) {
    for (uint8_t i = 0; i < 4; i++) {
        uint8_t offset = Rotate(tetromino[i], tetromino.GetRotation());
        uint8_t x = tetromino.GetPosition().x + offset % 4;
        uint8_t y = tetromino.GetPosition().y + offset / 4;

        board[y][x] = 0;
    }
}

bool Board::DoesTetrominoFit(const Tetromino &tetromino) {
    for (uint8_t i = 0; i < 4; i++) {
        uint8_t offset = Rotate(tetromino[i], tetromino.GetRotation());
        uint8_t x = tetromino.GetPosition().x + offset % 4;
        uint8_t y = tetromino.GetPosition().y + offset / 4;

        if (x >= width or y >= height or board[y][x] != 0) {
            return false;
        }
    }

    return true;
}

void Board::ClearRows() {
    uint16_t offset = 0;

    for (int32_t row = height - 1; row >= 0; row--) {
        if (std::all_of(board[row].begin(), board[row].end(), [](uint8_t x) { return x > 0; })) {
            offset++;
        } else {
            board[row + offset] = board[row];
        }
    }
}
