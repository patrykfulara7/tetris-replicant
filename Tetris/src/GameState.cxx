#include "GameState.hxx"

GameState::GameState(StateManager &stateManager, std::shared_ptr<GameContext> gameContext)
    : State(stateManager, gameContext), tetromino(0, 0, INITIAL_POSITION) {
    tetromino.tetromino = sequence.GetNumber();

    if (gameContext == nullptr) {
        auto gameContext = std::make_shared<GameContext>(Board(10, 21));

        gameContext->blockTextures.reserve(8);
        for (uint8_t i = 0; i < 8; i++) {
            gameContext->blockTextures.emplace_back(SOURCE_DIRECTORY "/Tetris/assets/images/" + std::to_string(i) +
                                                    ".png");
        }

        this->gameContext = gameContext;
    } else {
        this->gameContext->board = Board(10, 21);
    }

    this->gameContext->board.AddTetromino(tetromino);

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

    Automata::KeyCode key = dynamic_cast<Automata::KeyPressedEvent *>(&event)->GetKeyCode();

    switch (key) {
        case Automata::Key::C: {
            Automata::Application::Close();
        } break;

        case Automata::Key::R: {
            PopState();
            PushState(StateID::Game, gameContext);
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

    gameContext->board.RemoveTetromino(tetromino);
    glm::ivec2 previousPosition = tetromino.position;
    uint8_t previousRotation = tetromino.rotation;

    switch (nextAction) {
        case Action::None: {
        } break;

        case Action::MoveDown: {
            tetromino.position = tetromino.position + glm::ivec2(0, 1);
        } break;

        case Action::MoveLeft: {
            tetromino.position = tetromino.position + glm::ivec2(-1, 0);
        } break;

        case Action::MoveRight: {
            tetromino.position = tetromino.position + glm::ivec2(1, 0);
        } break;

        case Action::RotateLeft: {
            tetromino.rotation = (tetromino.rotation + 1) % 4;
        } break;

        case Action::RotateRight: {
            tetromino.rotation = (tetromino.rotation + 3) % 4;
        } break;
    }

    if (gameContext->board.DoesTetrominoFit(tetromino)) {
        gameContext->board.AddTetromino(tetromino);
    } else {
        tetromino.position = previousPosition;
        tetromino.rotation = previousRotation;
        gameContext->board.AddTetromino(tetromino);

        if (nextAction == Action::MoveDown) {
            gameContext->board.ClearRows();

            tetromino.tetromino = sequence.GetNumber();
            tetromino.position = INITIAL_POSITION;
            tetromino.rotation = 0;

            if (gameContext->board.DoesTetrominoFit(tetromino)) {
                gameContext->board.AddTetromino(tetromino);
            } else {
                PopState();
                PushState(StateID::GameOver, gameContext);
            }
        }
    }

    nextAction = Action::None;
}

void GameState::OnRender() {
    for (uint16_t row = 1; row < gameContext->board.GetHeight(); row++) {
        for (uint16_t col = 0; col < gameContext->board.GetWidth(); col++) {
            if (gameContext->board[row][col] != 0) {
                Automata::Renderer::Draw(glm::vec2(static_cast<double>(col * gameContext->TILE_SIZE),
                                                   static_cast<double>((row - 1) * gameContext->TILE_SIZE)),
                                         gameContext->blockTextures[gameContext->board[row][col] - 1]);
            }
        }
    }
}
