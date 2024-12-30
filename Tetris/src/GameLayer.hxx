#pragma once

#include "tetpch.hxx"

#include "StateManager.hxx"

class GameLayer : public Automata::Layer {
  private:
    StateManager stateManager;

  public:
    ~GameLayer() override = default;

    void OnAttach() override;
    void OnDetach() override;
    void OnEvent(Automata::Event &event) override;
    void OnUpdate(double deltaTime) override;
    void OnRender() override;
};
