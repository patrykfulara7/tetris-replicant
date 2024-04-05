#pragma once

#include <Automata.hxx>

class GameLayer : public Automata::Layer
{
public:
    ~GameLayer() override = default;

    void OnAttach() override;
    void OnDetach() override;
    void OnUpdate(double deltaTime) override;
    void OnRender() override;
};
