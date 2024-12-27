#include "GameState.hxx"

GameState::GameState(StateManager &stateManager)
    : State(stateManager), tetromino(0, 0, INITIAL_POSITION), board(10, 20) {
    blockTextures.reserve(8);
    for (uint8_t i = 0; i < 8; i++) {
        blockTextures.emplace_back(SOURCE_DIRECTORY "/Tetris/res/tex/" + std::to_string(i) + ".png");
    }

    tetromino.SetTetromino(sequence.GetNumber());
    board.AddTetromino(tetromino);

    fall = std::thread(&GameState::Fall, this);
}

GameState::~GameState() {
    // Bartek tu był.
    fall.detach();
}

void GameState::Fall() {
    using namespace std::chrono_literals;

    while (2137) {
        std::this_thread::sleep_for(1.5s);
        nextAction = Action::MoveDown;
    }
}

void GameState::OnEvent(Automata::Event &event) {
    if (event.GetEventType() != Automata::EventType::KeyPressed) {
        return;
    }

    auto keyPressedEvent = *dynamic_cast<Automata::KeyPressedEvent *>(&event);
    auto key = keyPressedEvent.GetKeyCode();

    switch (key) {
        case Automata::Key::C: {
            Automata::Application::Close();
        } break;

        case Automata::Key::J: {
            nextAction = Action::MoveDown;
        } break;

        case Automata::Key::H: {
            nextAction = Action::MoveLeft;
        } break;

        case Automata::Key::L: {
            nextAction = Action::MoveRight;
        } break;

        case Automata::Key::Q: {
            nextAction = Action::RotateLeft;
        } break;

        case Automata::Key::E: {
            nextAction = Action::RotateRight;
        } break;
    }
}

void GameState::OnUpdate(double deltaTime) {
    (void)deltaTime;

    board.RemoveTetromino(tetromino);
    glm::ivec2 previousPosition = tetromino.GetPosition();
    uint8_t previousRotation = tetromino.GetRotation();

    switch (nextAction) {
        case Action::None: {
        } break;

        case Action::MoveDown: {
            tetromino.SetPosition(tetromino.GetPosition() + glm::ivec2(0, 1));
        } break;

        case Action::MoveLeft: {
            tetromino.SetPosition(tetromino.GetPosition() + glm::ivec2(-1, 0));
        } break;

        case Action::MoveRight: {
            tetromino.SetPosition(tetromino.GetPosition() + glm::ivec2(1, 0));
        } break;

        case Action::RotateLeft: {
            tetromino.SetRotation((tetromino.GetRotation() + 1) % 4);
        } break;

        case Action::RotateRight: {
            tetromino.SetRotation((tetromino.GetRotation() + 3) % 4);
        } break;
    }

    if (board.DoesTetrominoFit(tetromino)) {
        board.AddTetromino(tetromino);
    } else {
        tetromino.SetPosition(previousPosition);
        tetromino.SetRotation(previousRotation);
        board.AddTetromino(tetromino);

        if (nextAction == Action::MoveDown) {
            board.ClearRows();

            tetromino.SetTetromino(sequence.GetNumber());
            tetromino.SetPosition(INITIAL_POSITION);
            tetromino.SetRotation(0);

            if (not board.DoesTetrominoFit(tetromino)) {
                SetUserPointer(std::make_shared<Board>(board));
                PopState();
                PushState(StateID::GameOver);
            }

            board.AddTetromino(tetromino);
        }
    }

    nextAction = Action::None;
}

void GameState::OnRender() {
    for (uint16_t row = 0; row < board.GetHeight(); row++) {
        for (uint16_t col = 0; col < board.GetWidth(); col++) {
            if (board[row][col] != 0) {
                Automata::Renderer::Draw(
                    glm::vec2(static_cast<double>(col * TILE_SIZE), static_cast<double>(row * TILE_SIZE)),
                    blockTextures[board[row][col] - 1]);
            }
        }
    }
}
