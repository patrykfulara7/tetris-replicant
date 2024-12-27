#include "GameOverState.hxx"

GameOverState::GameOverState(StateManager &stateManager)
    : State(stateManager), board(*std::static_pointer_cast<Board>(GetUserPointer())),
      blockTexture(SOURCE_DIRECTORY "/Tetris/res/tex/7.png") {
}

GameOverState::~GameOverState() {
}

void GameOverState::OnEvent(Automata::Event &event) {
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
            PopState();
            PushState(StateID::Game);
        }
    }
}

void GameOverState::OnUpdate(double deltaTime) {
    (void)deltaTime;
}

void GameOverState::OnRender() {
    for (uint16_t row = 0; row < board.GetHeight(); row++) {
        for (uint16_t col = 0; col < board.GetWidth(); col++) {
            if (board[row][col] != 0) {
                Automata::Renderer::Draw(
                    glm::vec2(static_cast<double>(col * TILE_SIZE), static_cast<double>(row * TILE_SIZE)),
                    blockTexture);
            }
        }
    }
}
