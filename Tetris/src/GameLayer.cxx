#include "Cache.hxx"
#include "GameLayer.hxx"
#include "GameOverState.hxx"
#include "GameState.hxx"
#include "StateIdentifiers.hxx"

void GameLayer::OnAttach() {
    stateManager.RegisterState<GameState>(StateID::Game);
    stateManager.RegisterState<GameOverState>(StateID::GameOver);

    auto cache = Cache::Create(Board(10, 21));

    cache->blockTextures.reserve(8);
    for (uint8_t i = 0; i < 8; i++) {
        cache->blockTextures.emplace_back(SOURCE_DIRECTORY "/Tetris/assets/images/" + std::to_string(i) + ".png");
    }

    stateManager.SetUserPointer(cache);

    stateManager.PushState(StateID::Game);
}

void GameLayer::OnDetach() {
}

void GameLayer::OnEvent(Automata::Event &event) {
    stateManager.OnEvent(event);
}

void GameLayer::OnUpdate(double deltaTime) {
    stateManager.OnUpdate(deltaTime);
}

void GameLayer::OnRender() {
    stateManager.OnRender();
}
