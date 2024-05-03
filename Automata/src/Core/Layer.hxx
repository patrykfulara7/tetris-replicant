#pragma once

#include "ampch.hxx"

#include "Events/Event.hxx"

namespace Automata {
    class Layer {
      public:
        virtual ~Layer() = default;

        virtual void OnAttach() = 0;
        virtual void OnDetach() = 0;
        virtual void OnEvent(Event &event) = 0;
        virtual void OnUpdate(double deltaTime) = 0;
        virtual void OnRender() = 0;
    };
} // namespace Automata
