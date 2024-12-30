#include "GameOverState.hxx"

GameOverState::GameOverState(StateManager &stateManager)
    : State(stateManager), cache(std::static_pointer_cast<Cache>(GetUserPointer())) {
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

        case Automata::Key::R: {
            PopState();
            PushState(StateID::Game);
        } break;
    }
}

void GameOverState::OnUpdate(double deltaTime) {
    (void)deltaTime;
}

void GameOverState::OnRender() {
    for (uint16_t row = 0; row < cache->board.GetHeight(); row++) {
        for (uint16_t col = 0; col < cache->board.GetWidth(); col++) {
            if (cache->board[row][col] != 0) {
                Automata::Renderer::Draw(
                    glm::vec2(static_cast<double>(col * cache->TILE_SIZE), static_cast<double>(row * cache->TILE_SIZE)),
                    cache->blockTextures[7]);
            }
        }
    }
}
