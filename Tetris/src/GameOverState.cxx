#include "GameOverState.hxx"

GameOverState::GameOverState(StateManager &stateManager, std::shared_ptr<GameContext> gameContext)
    : State(stateManager, gameContext) {
}

GameOverState::~GameOverState() {
}

void GameOverState::OnEvent(Automata::Event &event) {
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
    }
}

void GameOverState::OnUpdate(double deltaTime) {
    (void)deltaTime;
}

void GameOverState::OnRender() {
    for (uint16_t row = 1; row < gameContext->board.GetHeight(); row++) {
        for (uint16_t col = 0; col < gameContext->board.GetWidth(); col++) {
            if (gameContext->board[row][col] != 0) {
                Automata::Renderer::Draw(glm::vec2(static_cast<double>(col * gameContext->TILE_SIZE),
                                                   static_cast<double>((row - 1) * gameContext->TILE_SIZE)),
                                         gameContext->blockTextures[7]);
            }
        }
    }
}
