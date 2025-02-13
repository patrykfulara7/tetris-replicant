#pragma once

#include "tetpch.hxx"

class ImGuiLayer : public Automata::Layer {
  public:
    ~ImGuiLayer() override = default;

    void OnAttach() override;
    void OnDetach() override;
    void OnEvent(Automata::Event &event) override;
    void OnUpdate(double deltaTime) override;
    void OnRender() override;
};
